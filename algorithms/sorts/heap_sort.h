#pragma once

namespace ystd {

    namespace NPrivate {
        template<typename TIter, typename TCompare>
        struct THeap {
            TIter Beg;
            int HeapSize;
            int ArraySize;
            TCompare Cmp;

            static inline int Left(int idx) {
                return ((idx + 1) << 1) - 1;
            }

            static inline int Right(int idx) {
                return (idx + 1) << 1;
            }

            static inline int Parent(int idx) {
                return ((idx + 1) >> 1) - 1;
            }

            /// Fixes element idx to make idx subtree a correct max-heap
            /// Requires: left and right subtrees of idx be a correct max-heaps
            void Heapify(int idx) {
                const int sz = HeapSize;
                int largest = -1;
                for (;;) {
                    largest = idx;
                    const int l = Left(idx);
                    const int r = Right(idx);
                    if (l < sz && Cmp(Beg[idx], Beg[l]))
                        largest = l;
                    if (r < sz && Cmp(Beg[largest], Beg[r]))
                        largest = r;
                    if (largest != idx) {
                        swap(Beg[idx], Beg[largest]);
                        idx = largest;
                    } else
                        break;
                }
            }

            void BuildHeap() {
                const int start = (ArraySize >> 1) - 1;
                for (int i = start; i >= 0; --i)
                    Heapify(i);
            }

            THeap(TIter beg, int heapSize, int arraySize, TCompare cmp = TCompare())
                : Beg(beg)
                , HeapSize(heapSize)
                , ArraySize(arraySize)
                , Cmp(cmp) {
                BuildHeap();
            }
        };
    }

template<typename TIterator, typename TCompare>
void HeapSort(TIterator beg, TIterator end, TCompare cmp) {
    const int len = end - beg;
    NPrivate::THeap< TIterator, TCompare > h(beg, len, len, cmp);
    for (int i = len - 1; i > 0; --i) {
        std::swap(beg[0], beg[i]);
        --h.HeapSize;
        h.Heapify(0);
    }
}

template<typename TIterator>
void HeapSort(TIterator beg, TIterator end) {
    HeapSort(beg, end, std::less< typename TIterator::value_type >());
}

} // namespace yu
