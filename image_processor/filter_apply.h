#ifndef CPP_HSE_FILTER_APPLY_H
#define CPP_HSE_FILTER_APPLY_H

#pragma once

#include "parser.h"
#include "filters.h"
#include <map>

namespace filter_factories {
BaseFilter* MakeCropFilter(const FilterDescriptor& fd);

BaseFilter* MakeNegativeFilter(const FilterDescriptor& fd);

BaseFilter* MakeGreyScaleFilter(const FilterDescriptor& fd);

BaseFilter* MakeSharpeningFilter(const FilterDescriptor& fd);

BaseFilter* MakeEdgeDetectionFilter(const FilterDescriptor& fd);

BaseFilter* MakeGaussianBlurFilter(const FilterDescriptor& fd);

}  // namespace filter_factories

class FilterApply {
public:
    FilterApply()
        : filter_to_makers_({{"-crop", &filter_factories::MakeCropFilter},
                             {"-neg", &filter_factories::MakeNegativeFilter},
                             {"-gs", &filter_factories::MakeGreyScaleFilter},
                             {"-sharp", &filter_factories::MakeSharpeningFilter},
                             {"-edge", &filter_factories::MakeEdgeDetectionFilter},
                             {"-blur", &filter_factories::MakeGaussianBlurFilter}}) {
    }

public:
    using FilterApplier = BaseFilter* (*)(const FilterDescriptor&);
    using FilterToMakerMap = std::map<std::string_view, FilterApplier>;

    [[maybe_unused]] void AddFilterMaker(std::string_view name, FilterApplier factory);

    FilterApplier GetFilterApplierMaker(std::string_view name) const;

    BaseFilter* CreateFilter(const FilterDescriptor& descriptor) const;

protected:
    FilterToMakerMap filter_to_makers_;
};

#endif  // CPP_HSE_FILTER_APPLY_H
