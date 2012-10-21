#pragma once

#include <algorithm>
#include <vector>

namespace ystd {

typedef unsigned int ui32;
//typedef int ui32;

void RadixSort(std::vector<ui32>::iterator beg, std::vector<ui32>::iterator end) {
    const int DIGITS_COUNT = 32;
    typedef std::vector<ui32>::iterator TIter;

    std::vector<ui32> tmp(end - beg);
    for (ui32 i = 0; i < DIGITS_COUNT; ++i) {
        //Print(beg, end);
        const ui32 mask = 1 << i;
        TIter tmpIter = tmp.begin();
        for (TIter iter = beg; iter != end; ++iter)
            if (((*iter) & mask) == 0)
                *tmpIter++ = *iter;
        for (TIter iter = beg; iter != end; ++iter)
            if (((*iter) & mask) != 0)
                *tmpIter++ = *iter;
        for (TIter iter = beg, tmpIter = tmp.begin(); iter != end; ++iter, ++tmpIter)
            *iter = *tmpIter;
    }
    //Print(beg, end);
}

} // namespace ystd
