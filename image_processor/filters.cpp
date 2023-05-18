#include "filters.h"
#include "bitmap.h"

#include <algorithm>
#include <cmath>

const int MAX_PIX_VAL = 255;
const double MAX_PIX_VAL_D = 255.;

void ApplyColors(Bitmap::Pixel& pixel, double red = 0, double green = 0, double blue = 0) {
    pixel.red = std::min(MAX_PIX_VAL, std::max(0, static_cast<int32_t>(red)));
    pixel.green = std::min(MAX_PIX_VAL, std::max(0, static_cast<int32_t>(green)));
    pixel.blue = std::min(MAX_PIX_VAL, std::max(0, static_cast<int32_t>(blue)));
}

template <typename T>
void ApplyMatrix(const std::vector<std::vector<T>>& matrix, Bitmap& bitmap) {
    struct CurrentColour {
        T red = 0;
        T green = 0;
        T blue = 0;
    };

    Bitmap::PixelArray result;
    result.SetHeight(bitmap.GetHeight());
    result.SetWidth(bitmap.GetWidth());

    int edge_value_x = matrix.size() / 2;
    int edge_value_y = matrix[0].size() / 2;
    for (int i = 0; i < bitmap.GetHeight(); ++i) {
        for (int j = 0; j < bitmap.GetWidth(); ++j) {
            Bitmap::Pixel pixel{};
            CurrentColour cur_colour;

            for (int di = -edge_value_x; di <= edge_value_x; ++di) {
                for (int dj = -edge_value_y; dj <= edge_value_y; ++dj) {
                    int x = i + di;
                    int y = j + dj;
                    x = std::min(std::max(x, 0), static_cast<int>(bitmap.GetHeight()) - 1);
                    y = std::min(std::max(y, 0), static_cast<int>(bitmap.GetWidth()) - 1);
                    Bitmap::Pixel cur_pixel = bitmap.GetPixel(x, y);
                    cur_colour.red += cur_pixel.red * matrix[di + edge_value_x][dj + edge_value_y];
                    cur_colour.green += cur_pixel.green * matrix[di + edge_value_x][dj + edge_value_y];
                    cur_colour.blue += cur_pixel.blue * matrix[di + edge_value_x][dj + edge_value_y];
                }
            }
            ApplyColors(pixel, cur_colour.red, cur_colour.green, cur_colour.blue);
            result.PushBack(pixel);
        }
    }
    bitmap.CopyPixels(result);
}

void CropFilter::Apply(Bitmap& bitmap) {
    if (new_height_ <= bitmap.GetHeight()) {  // new_height_ = min(new_height_, current_height)
        bitmap.SetFileHeight(new_height_);
    } else {
        new_height_ = bitmap.GetHeight();
    }

    if (new_width_ <= bitmap.GetWidth()) {
        bitmap.SetFileWidth(new_width_);
    } else {
        new_width_ = bitmap.GetWidth();
    }

    Bitmap::PixelArray result;
    result.SetHeight(new_height_);
    result.SetWidth(new_width_);
    for (size_t i = bitmap.GetHeight() - new_height_; i < bitmap.GetHeight(); ++i) {
        for (size_t j = 0; j < new_width_; ++j) {
            result.PushBack(bitmap.GetPixel(i, j));
        }
    }
    bitmap.CopyPixels(result);
}

uint8_t TransformToNegative(uint8_t colour) {
    return static_cast<uint8_t>(std::round((1 - (static_cast<double>(colour) / MAX_PIX_VAL_D)) * MAX_PIX_VAL_D));
}

void NegativeFilter::Apply(Bitmap& bitmap) {
    for (size_t i = 0; i < bitmap.GetHeight(); ++i) {
        for (size_t j = 0; j < bitmap.GetWidth(); ++j) {
            Bitmap::Pixel cur_pixel = bitmap.GetPixel(i, j);
            uint8_t new_r = TransformToNegative(cur_pixel.red);
            uint8_t new_g = TransformToNegative(cur_pixel.green);
            uint8_t new_b = TransformToNegative(cur_pixel.blue);
            ApplyColors(bitmap.GetPixel(i, j), new_r, new_g, new_b);
        }
    }
}

void GreyScaleFilter::Apply(Bitmap& bitmap) {
    const double r_multiplier = 0.299;
    const double b_multiplier = 0.114;
    const double g_multiplier = 0.587;
    for (size_t i = 0; i < bitmap.GetHeight(); ++i) {
        for (size_t j = 0; j < bitmap.GetWidth(); ++j) {
            Bitmap::Pixel cur_pixel = bitmap.GetPixel(i, j);
            double new_r = r_multiplier * static_cast<double>(cur_pixel.red);
            double new_g = g_multiplier * static_cast<double>(cur_pixel.green);
            double new_b = b_multiplier * static_cast<double>(cur_pixel.blue);
            uint8_t new_colour = static_cast<uint8_t>(new_r + new_g + new_b);
            ApplyColors(bitmap.GetPixel(i, j), new_colour, new_colour, new_colour);
        }
    }
}

void SharpeningFilter::Apply(Bitmap& bitmap) {
    ApplyMatrix(sharpening_matrix_, bitmap);
}

void EdgeDetectionFilter::Apply(Bitmap& bitmap) {
    GreyScaleFilter::Apply(bitmap);
    ApplyMatrix(edge_detection_matrix_, bitmap);
    for (size_t i = 0; i < bitmap.GetHeight(); ++i) {
        for (size_t j = 0; j < bitmap.GetWidth(); ++j) {
            if (bitmap.GetPixel(i, j).red > threshold_ * MAX_PIX_VAL_D) {
                ApplyColors(bitmap.GetPixel(i, j), MAX_PIX_VAL, MAX_PIX_VAL, MAX_PIX_VAL);
            } else {
                ApplyColors(bitmap.GetPixel(i, j), 0, 0, 0);
            }
        }
    }
}

double GaussFunction(int32_t x, int32_t y, int32_t sigma) {
    return pow(M_E, (-x * x + y * y)) / (2 * (sigma * sigma)) / (2 * M_PI * sigma * sigma);
}

// тут применена оптимизация с https://en.wikipedia.org/wiki/Gaussian_blur
void GaussianBlurFilter::Apply(Bitmap& bitmap) {
    double gauss_func_sum = 0;
    for (int x = -3 * sigma_; x <= 3 * sigma_; ++x) {
        std::vector<double> temporary_matrix;
        for (int y = -3 * sigma_; y <= 3 * sigma_; ++y) {
            double gauss_function = GaussFunction(x, y, sigma_);
            gauss_func_sum += gauss_function;
            temporary_matrix.push_back(gauss_function);
        }
        gaussian_blur_matrix_.push_back(temporary_matrix);
    }
    for (int x = -3 * sigma_; x <= 3 * sigma_; ++x) {
        for (int y = -3 * sigma_; y <= 3 * sigma_; ++y) {
            gaussian_blur_matrix_[x + 3 * sigma_][y + 3 * sigma_] /= gauss_func_sum;
        }
    }
    ApplyMatrix(gaussian_blur_matrix_, bitmap);
}
