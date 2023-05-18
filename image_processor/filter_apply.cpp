#include "filter_apply.h"

#include <stdexcept>

namespace filter_factories {
BaseFilter* MakeCropFilter(const FilterDescriptor& fd) {
    if (fd.filter_name != "-crop" || fd.filter_params.size() != 2) {
        throw std::invalid_argument("Invalid argument");
    }
    std::string height_str = {fd.filter_params[0].begin(), fd.filter_params[0].end()};
    std::string width_str = {fd.filter_params[1].begin(), fd.filter_params[1].end()};
    return new CropFilter(std::stoi(height_str), std::stoi(width_str));
}

BaseFilter* MakeNegativeFilter(const FilterDescriptor& fd) {
    if (fd.filter_name != "-neg" || !fd.filter_params.empty()) {
        throw std::invalid_argument("Invalid argument");
    }
    return new NegativeFilter;
}

BaseFilter* MakeGreyScaleFilter(const FilterDescriptor& fd) {
    if (fd.filter_name != "-gs" || !fd.filter_params.empty()) {
        throw std::invalid_argument("Invalid argument");
    }
    return new GreyScaleFilter;
}

BaseFilter* MakeSharpeningFilter(const FilterDescriptor& fd) {
    if (fd.filter_name != "-sharp" || !fd.filter_params.empty()) {
        throw std::invalid_argument("Invalid argument");
    }
    return new SharpeningFilter;
}

BaseFilter* MakeEdgeDetectionFilter(const FilterDescriptor& fd) {
    if (fd.filter_name != "-edge" || fd.filter_params.size() != 1) {
        throw std::invalid_argument("Invalid argument");
    }
    std::string threshold(fd.filter_params[0].begin(), fd.filter_params[0].end());
    return new EdgeDetectionFilter(std::stod(threshold));
}

BaseFilter* MakeGaussianBlurFilter(const FilterDescriptor& fd) {
    if (fd.filter_name != "-blur" || fd.filter_params.size() != 1) {
        throw std::invalid_argument("Invalid argument");
    }
    std::string sigma(fd.filter_params[0].begin(), fd.filter_params[0].end());
    int int_sigma = stoi(sigma);
    if (int_sigma <= 0) {
        throw std::invalid_argument("Sigma must be > 0");
    }
    return new GaussianBlurFilter(int_sigma);
}

}  // namespace filter_factories

[[maybe_unused]] void FilterApply::AddFilterMaker(std::string_view name, FilterApplier applier) {
    filter_to_makers_.insert({name, applier});
}

FilterApply::FilterApplier FilterApply::GetFilterApplierMaker(std::string_view name) const {
    FilterToMakerMap::const_iterator it = filter_to_makers_.find(name);
    if (it != filter_to_makers_.end()) {
        return it->second;
    }
    return nullptr;
}

BaseFilter* FilterApply::CreateFilter(const FilterDescriptor& descriptor) const {
    FilterApplier gear = GetFilterApplierMaker(descriptor.filter_name);
    if (!gear) {
        return nullptr;
    }
    BaseFilter* current_filter = gear(descriptor);
    return current_filter;
}
