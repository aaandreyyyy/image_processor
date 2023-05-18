#include "bitmap.h"

#include <fstream>
#include <stdexcept>

bool Bitmap::Load(const char* file_name) {
    std::fstream file;
    file.open(file_name, std::ios_base::in | std::ios_base::binary);
    if (!file.is_open()) {
        return false;
    }
    Load(file);
    file.close();
    return true;
}

bool Bitmap::Load(std::istream& stream) {
    try {
        stream.read(reinterpret_cast<char*>(&bmp_header_), sizeof(bmp_header_));
        stream.read(reinterpret_cast<char*>(&dib_header_), sizeof(dib_header_));
    } catch (std::exception& e) {
        return false;
    }

    const std::streamsize rubbish_between_pixel_lines = (4 - (3 * dib_header_.width) % 4) % 4;
    pixels_.SetHeight(dib_header_.height);
    pixels_.SetWidth(dib_header_.width);
    for (size_t row = 0; row < dib_header_.height; ++row) {
        for (size_t column = 0; column < dib_header_.width; ++column) {
            Pixel pixel{};
            stream.read(reinterpret_cast<char*>(&pixel), sizeof(pixel));
            pixels_.PushBack(pixel);
        }
        stream.ignore(rubbish_between_pixel_lines);
    }

    return true;
}

bool Bitmap::WriteFile(const char* file_name) {
    std::ofstream file;
    file.open(file_name, std::ios_base::out | std::ios_base::binary);
    if (!file.is_open()) {
        return false;
    }
    WriteFile(file);
    file.close();
    return true;
}

bool Bitmap::WriteFile(std::ostream& stream) {
    stream.write(reinterpret_cast<char*>(&bmp_header_), sizeof(bmp_header_));
    stream.write(reinterpret_cast<char*>(&dib_header_), sizeof(dib_header_));

    const int64_t rubbish_between_pixel_lines = (4 - (dib_header_.width * 3) % 4) % 4;
    for (size_t row = 0; row < dib_header_.height; ++row) {
        for (size_t column = 0; column < dib_header_.width; ++column) {
            stream.write(reinterpret_cast<char*>(&pixels_.GetPixel(row, column)),
                         sizeof(pixels_.GetPixel(row, column)));
        }
        static const uint32_t RUBBISH = 0x55AA55AA;
        stream.write(reinterpret_cast<const char*>(&RUBBISH), rubbish_between_pixel_lines);
    }
    return true;
}
