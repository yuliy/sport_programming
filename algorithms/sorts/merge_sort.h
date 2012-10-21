#pragma once

#include <algorithm>
#include <vector>

namespace ystd {

    namespace NPrivate {
        template<typename TIterator, typename TCompare>
        void Merge(
            TIterator beg1, TIterator end1,
            TIterator beg2, TIterator end2,
            TCompare cmp, std::vector<typename TIterator::value_type> &buf) {
            typename std::vector<typename TIterator::value_type>::iterator bufIter = buf.begin();
            while (beg1 != end1 && beg2 != end2)
                *bufIter++ = cmp(*beg2, *beg1) ? *beg2++ : *beg1++;
            while (beg1 != end1)
                *bufIter++ = *beg1++;
            while (beg2 != end2)
                *bufIter++ = *beg2++;
        }

        template<typename TIterator, typename TCompare>
        void MergeSort(TIterator beg, TIterator end, TCompare cmp, std::vector<typename TIterator::value_type> &buf) {
            if ((end - beg) <= 1)
                return;

            TIterator midIter = beg + (end - beg)/2;
            MergeSort(beg, midIter, cmp, buf);
            MergeSort(midIter, end, cmp, buf);
            Merge(beg, midIter, midIter, end, cmp, buf);

            typename std::vector<typename TIterator::value_type>::iterator bufIter = buf.begin();
            for (TIterator iter = beg; iter != end; ++iter, ++bufIter)
                *iter = *bufIter;
        }
    } // NPrivate

template<typename TIterator, typename TCompare>
void MergeSort(TIterator beg, TIterator end, TCompare cmp) {
    std::vector<typename TIterator::value_type> buf(end - beg);
    ystd::NPrivate::MergeSort(beg, end, cmp, buf);
}

template<typename TIterator>
void MergeSort(TIterator beg, TIterator end) {
    MergeSort(beg, end, std::less< typename TIterator::value_type >());
}

} // namespace ystd
