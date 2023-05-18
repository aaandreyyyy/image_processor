#ifndef CPP_HSE_PARSER_H
#define CPP_HSE_PARSER_H

#pragma once

#include <string_view>
#include <vector>

struct FilterDescriptor {
    std::string_view filter_name;
    std::vector<std::string_view> filter_params;
};

class CmdLineParser {
public:
    static const int MIN_PARAM_NUMBER = 3;  // program name, input, output at least

    /*!
     * Takes file in, file out, params
     * Fills input_file_name_, output_file_name_, filter_descriptors_
     * */
    bool Parse(int argc, char* argv[]);

    std::string_view GetInputFileName() const {
        return input_file_name_;
    }

    std::string_view GetOutputFileName() const {
        return output_file_name_;
    }

    const std::vector<FilterDescriptor*>& GetFilterDescriptors() const {
        return filter_descriptors_;
    }

protected:
    std::string_view input_file_name_;
    std::string_view output_file_name_;
    std::vector<FilterDescriptor*> filter_descriptors_;
};

#endif  // CPP_HSE_PARSER_H
