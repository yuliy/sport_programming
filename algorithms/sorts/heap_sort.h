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
public:
    typedef typename TCont::const_iterator TConstIterator;

    THeap() {
        Cont.push_back(16);
        Cont.push_back(14);
        Cont.push_back(10);
        Cont.push_back(8);
        Cont.push_back(7);
        Cont.push_back(9);
        Cont.push_back(3);
        Cont.push_back(2);
        Cont.push_back(4);
        Cont.push_back(1);

        int i = 0;
        std::cout << i << std::endl
            << Left(i) << "\t" << Cont[Left(i)] << std::endl
            << Right(i) << "\t" << Cont[Right(i)] << std::endl
            << Parent(2) << std::endl;
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
};

} // namespace yu
