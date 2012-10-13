#pragma once

#include <vector>
#include <algorithm>
#include <iterator>

namespace ystd {

/**
  * Heap - max-heap (with maximum in root)
  */
template<typename T, typename TCompare = std::less<T>, typename TCont = std::vector<T> >
class THeap {
private:
    typedef typename TCont::iterator TIterator;
    TCont Cont;
    TCompare Cmp;
private:
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
        const int sz = Size();
        int largest = -1;
        for (;;) {
            largest = idx;
            const int l = Left(idx);
            const int r = Right(idx);
            if (l < sz && Cmp(Cont[idx], Cont[l]))
                largest = l;
            if (r < sz && Cmp(Cont[largest], Cont[r]))
                largest = r;
            if (largest != idx) {
                swap(Cont[idx], Cont[largest]);
                idx = largest;
            } else
                break;
        }
    }

    void BuildHeap() {
        const int start = (Size() >> 1) - 1;
        for (int i = start; i >= 0; --i)
            Heapify(i);
    }
public:
    typedef typename TCont::const_iterator TConstIterator;

    THeap() {
    }

    THeap(TCompare cmp)
        : Cmp(cmp) {
    }

    THeap(const THeap &other)
        : Cont(other.Cont)
        , Cmp(other.Cmp) {
    }

    template<typename TOtherIter>
    THeap(TOtherIter beg, TOtherIter end, TCompare cmp = TCompare()) {
        std::copy(
            beg, end,
            std::back_inserter< TCont >(Cont)
        );
        BuildHeap();
    }

    bool Empty() const {
        return Cont.empty();
    }

    size_t Size() const {
        return Cont.size();
    }

    const T &Root() const {
        return Cont.front();
    }

    T ExtractRoot() {
        T res = Root();
        Cont.front() = Cont.back();
        Cont.pop_back();
        Heapify(0);
    }

    void Insert(const T &elem) {
        //
    }

    void Print() const {
        for (TConstIterator iter = Cont.begin(), end = Cont.end(); iter != end; ++iter)
            std::cout << *iter << "\t";
        std::cout << std::endl;
    }
};

} // namespace yu
