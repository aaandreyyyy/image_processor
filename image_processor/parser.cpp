#include "parser.h"

#include <iostream>
#include <memory>

void PrintHelp() {
    std::cout << "Image processor:" << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "Cmd arguments format:" << std::endl;
    std::cout << "      program_name input_file_path output_file_path filters" << std::endl;
    std::cout << "Filters:" << std::endl;
    std::cout << "      -crop w h || Crop" << std::endl;
    std::cout << "      -gs || Grey scale" << std::endl;
    std::cout << "      -neg || Negative" << std::endl;
    std::cout << "      -sharp || Sharpening" << std::endl;
    std::cout << "      -blur sigma || Blur" << std::endl;
}

bool CmdLineParser::Parse(int argc, char* argv[]) {
    if (argc == 1) {
        PrintHelp();
        return true;
    }
    if (argc < MIN_PARAM_NUMBER) {
        return false;
    }

    size_t i = 1;
    input_file_name_ = argv[i++];
    output_file_name_ = argv[i++];

    for (; i < argc; ++i) {
        if (argv[i][0] == '-') {
            FilterDescriptor* descriptor = new FilterDescriptor;
            descriptor->filter_name = argv[i];
            filter_descriptors_.push_back(descriptor);
        } else if (filter_descriptors_.empty()) {
            return false;
        } else {
            filter_descriptors_.back()->filter_params.push_back(argv[i]);
        }
    }
    return true;
}
