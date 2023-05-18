#include "parser.h"
#include "filter_apply.h"
#include "bitmap.h"

#include <cassert>
#include <iostream>
#include <memory>

int main(int argc, char* argv[]) try {
    CmdLineParser parser;
    if (!parser.Parse(argc, argv)) {
        std::cerr << "\033[1;31m"
                  << "Parsing error"
                  << "\033[0m\n";
    }
    if (argc == 1) {
        return 0;
    }
    Bitmap bitmap;

    std::string input_filename = {parser.GetInputFileName().begin(), parser.GetInputFileName().end()};
    if (!bitmap.Load(input_filename.c_str())) {
        std::cerr << "\033[1;31m"
                  << "error occurred loading the input file"
                  << "\033[0m\n";
    }
    if (bitmap.IsEmpty()) {
        std::cerr << "\033[1;31m"
                  << "input file is empty"
                  << "\033[0m\n";
    }

    FilterApply filter_apply;
    for (auto descriptor : parser.GetFilterDescriptors()) {
        std::shared_ptr<BaseFilter> filter(filter_apply.CreateFilter(*descriptor));
        assert(filter);
        filter->Apply(bitmap);
        delete descriptor;
    }

    std::string output_filename = {parser.GetOutputFileName().begin(), parser.GetOutputFileName().end()};
    assert(bitmap.WriteFile(output_filename.c_str()));
    return 0;
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return -1;
} catch (...) {
    return -2;
}
