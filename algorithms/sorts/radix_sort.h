#pragma once

#include <algorithm>

namespace ystd {

template<typename TIterator, typename TCompare>
void RadixSort(TIterator beg, TIterator end, TCompare cmp) {
}

template<typename TIterator>
void RadixSort(TIterator beg, TIterator end) {
    RadixSort(beg, end, std::less< typename TIterator::value_type >());
}

} // namespace ystd
