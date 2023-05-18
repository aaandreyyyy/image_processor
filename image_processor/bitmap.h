#pragma once

#include <cstdint>
#include <iostream>
#include <vector>
#include <tuple>

class Bitmap {
public:
    struct BMPHeader {
        uint16_t signature;
        uint32_t file_size;
        uint32_t dummy;
        uint32_t bitarray_offset;
    } __attribute__((__packed__));

    struct DIBHeader {
        uint32_t dib_header_size;
        uint32_t width;
        uint32_t height;
        uint64_t dummy;
        uint32_t raw_bitmap_data_size;
        uint64_t dummy2;
        uint64_t dummy3;
    } __attribute__((__packed__));

    struct Pixel {
        uint8_t blue = 0;
        uint8_t green = 0;
        uint8_t red = 0;

        bool operator==(const Pixel& other) const {
            return std::tie(blue, green, red) == std::tie(other.blue, other.green, other.red);
        }

        bool operator!=(const Pixel& other) const {
            return !(*this == other);
        }
    };

public:
    void SetFileWidth(size_t new_width) {
        dib_header_.width = new_width;
    }

    void SetFileHeight(size_t new_height) {
        dib_header_.height = new_height;
    }

    Pixel& GetPixel(size_t row, size_t column) {
        return pixels_.GetPixel(row, column);
    }

    [[maybe_unused]] const Pixel& GetPixel(size_t row, size_t column) const {
        return pixels_.GetPixel(row, column);
    }

    uint32_t GetHeight() const {
        return pixels_.GetHeight();
    }

    uint32_t GetWidth() const {
        return pixels_.GetWidth();
    }

    bool IsEmpty() const {
        return pixels_.IsEmpty();
    }

public:
    class PixelArray {
    public:
        PixelArray() = default;

        void PushBack(Pixel pixel) {
            pixel_array_elements_.push_back(pixel);
        }

        Pixel& GetPixel(size_t row, size_t column) {
            return pixel_array_elements_[pixel_array_width_ * row + column];
        }

        void SetHeight(size_t row) {
            pixel_array_height_ = row;
        }

        void SetWidth(size_t column) {
            pixel_array_width_ = column;
        }

        const Pixel& GetPixel(size_t row, size_t column) const {
            return pixel_array_elements_[pixel_array_width_ * row + column];
        }

        uint32_t GetHeight() const {
            return pixel_array_height_;
        }

        uint32_t GetWidth() const {
            return pixel_array_width_;
        }

        bool IsEmpty() const {
            return pixel_array_elements_.empty();
        }

        void Fill(size_t height, size_t width, uint8_t default_red = 0, uint8_t default_green = 0,
                  uint8_t default_blue = 0) {
            pixel_array_width_ = width;
            pixel_array_height_ = height;
            for (size_t i = 0; i < height * width; ++i) {
                Pixel pixel{default_blue, default_green, default_red};
                pixel_array_elements_.push_back(pixel);
            }
        }

    protected:
        size_t pixel_array_height_;
        size_t pixel_array_width_;
        std::vector<Pixel> pixel_array_elements_;
    };

    void CopyPixels(const PixelArray& other) {
        pixels_ = other;
    }

protected:
    PixelArray pixels_;
    BMPHeader bmp_header_;
    DIBHeader dib_header_;

public:
    bool Load(std::istream& stream);

    bool Load(const char* file_name);

    bool WriteFile(const char* file_name);

    bool WriteFile(std::ostream& stream);
};
