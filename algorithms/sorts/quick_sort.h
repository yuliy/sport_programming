#pragma once

#include <algorithm>

namespace ystd {

template<typename TIterator, typename TCompare>
void QuickSort(TIterator beg, TIterator end, TCompare) {
}

template<typename TIterator>
void QuickSort(TIterator beg, TIterator end) {
    QuickSort(beg, end, std::less< typename TIterator::value_type >());
}

} // namespace ystd
