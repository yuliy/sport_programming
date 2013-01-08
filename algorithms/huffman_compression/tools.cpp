#include <tools.h>

#include <iostream>

using namespace std;

namespace ystd {

//
// TBitBuf
//

TBitBuf::TBitBuf() {
}

void TBitBuf::WriteByte(unsigned char symbol) {
    const int sym = symbol;
    for (int i = 0; i < 8; ++i) {
        const int mask = 1 << i;
        const bool bit = sym & mask;
        Bits.push_back(bit);
    }
}

void TBitBuf::WriteBit(bool bit) {
    Bits.push_back(bit);
}

void TBitBuf::Clear() {
    Bits.clear();
}

size_t TBitBuf::Size() const {
    return Bits.size();
}

size_t TBitBuf::Empty() const {
    return Bits.empty();
}

const vector<bool> &TBitBuf::GetBits() const {
    return Bits;
}

} // namespace ystd
