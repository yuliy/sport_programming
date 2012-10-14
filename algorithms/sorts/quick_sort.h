#pragma once

#include <algorithm>

namespace ystd {

template<typename TIterator, typename TCompare>
TIterator Partition(TIterator beg, TIterator end, TCompare cmp) {
    typedef typename TIterator::difference_type T;
    TIterator pivotIter = end - 1;
    const T pivot = *pivotIter;
    TIterator qIter = beg;
    for (TIterator iter = beg; iter != pivotIter; ++iter) {
        if (cmp(*iter, pivot)) {
            std::swap(*qIter, *iter);
            ++qIter;
        }
    }

    std::swap(*qIter, *pivotIter);
    return qIter;
}

template<typename TIterator, typename TCompare>
void QuickSort(TIterator beg, TIterator end, TCompare cmp) {
    if (beg < end) {
        const TIterator qIter = Partition(beg, end, cmp);
        QuickSort(beg, qIter, cmp);
        QuickSort(qIter + 1, end, cmp);
    }
}

template<typename TIterator>
void QuickSort(TIterator beg, TIterator end) {
    QuickSort(beg, end, std::less< typename TIterator::value_type >());
}

} // namespace ystd
