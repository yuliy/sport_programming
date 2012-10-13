#pragma once

#include <vector>

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
        for (int i = Size() / 2; i >= 0; --i)
            Heapify(i);
    }
public:
    typedef typename TCont::const_iterator TConstIterator;

    THeap() {
        /*
        Cont.push_back(16);
        Cont.push_back(4);
        Cont.push_back(10);
        Cont.push_back(14);
        Cont.push_back(7);
        Cont.push_back(9);
        Cont.push_back(3);
        Cont.push_back(2);
        Cont.push_back(8);
        Cont.push_back(1);
        */
        Cont.push_back(4);
        Cont.push_back(1);
        Cont.push_back(3);
        Cont.push_back(2);
        Cont.push_back(16);
        Cont.push_back(9);
        Cont.push_back(10);
        Cont.push_back(14);
        Cont.push_back(8);
        Cont.push_back(7);

        BuildHeap();
    }

    THeap(const THeap &other)
        : Cont(other.Cont) {
    }

    template<typename TContIter>
    THeap(TContIter beg, TContIter end) {
    }

    bool Empty() const {
        return Cont.empty();
    }

    size_t Size() const {
        return Cont.size();
    }

    void Print() const {
        for (TConstIterator iter = Cont.begin(), end = Cont.end(); iter != end; ++iter)
            std::cout << *iter << "\t";
        std::cout << std::endl;
    }
};

} // namespace yu
