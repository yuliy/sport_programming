#include "radix.h"

#include <iostream>

using namespace std;

namespace ystd {

typedef vector<ui32> TBucket;
typedef vector<TBucket> TBuckets;

static void ByteSort(vector<ui32> &v, int bnum) {
    TBuckets buckets(256);
    const ui32 mask = 0xFF << (8*bnum);
    for (vector<ui32>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        const ui32 key = (*iter & mask) >> (8*bnum);
        buckets[key].push_back(*iter);
    }

    for (int i = 0, pos = 0; i < 256; ++i) {
        const TBucket &bucket = buckets[i];
        for (TBucket::const_iterator iter = bucket.begin(); iter != bucket.end(); ++iter)
            v[pos++] = *iter;
    }
}

void RadixSort(vector<ui32> &v) {
    for (int i = 0; i < 4; ++i)
        ByteSort(v, i);
}

} // namespace ystd
