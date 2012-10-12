#pragma once

#include <vector>

namespace ystd {

    template<typename T, typename TCont = std::vector<T> >
    class MaxHeap {
    private:
    public:
        TCont Cont;
        typedef typename TCont::iterator TIter;
        typedef typename TCont::const_iterator TCIter;
    private:
    public:
        //          0
        //      1       2
        //    3   4   5   6
        //
        TIter Parent(TIter beg, TIter iter) {
            const int idx = iter - beg;
            //const int parentIdx = (idx >> 1) + 
        }
    public:
        MaxHeap() {
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

            //std::cout << "7\t" << 
        }
    };

} // namespace yu
