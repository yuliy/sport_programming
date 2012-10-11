#pragma once

#include <vector>

namespace ystd {

    template<typename T, typename TCont = std::vector<T> >
    class MaxHeap {
    private:
        TCont Cont;
        typedef typename TCont::iterator TIter;
        typedef typename TCont::const_iterator TCIter;
    private:
        //          0
        //      1       2
        //    3   4   5   6
        //
        TIter Parent(TIter beg, TIter iter) {
            const int idx = iter - beg;
            //const int parentIdx = (idx >> 1) + 
        }
    public:
        //
    };

} // namespace yu
