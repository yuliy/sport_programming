#pragma once

#include <algorithm>

namespace ystd {

template<typename TIterator, typename TCompare>
typename TIterator::difference_type Partition(TIterator beg, TIterator end, TCompare cmp) {
    return 0;
}

template<typename TIterator, typename TCompare>
void QuickSort(TIterator beg, TIterator end, TCompare cmp) {
    if (beg < end) {
        const typename TIterator::difference_type q = Partition(beg, end, cmp);
        QuickSort(beg, beg + q - 1, cmp);
        QuickSort(beg + q + 1, end, cmp);
    }
}

template<typename TIterator>
void QuickSort(TIterator beg, TIterator end) {
    QuickSort(beg, end, std::less< typename TIterator::value_type >());
}

} // namespace ystd
