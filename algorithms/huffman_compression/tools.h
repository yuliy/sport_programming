#pragma once

#include <vector>

namespace ystd {
    typedef std::vector<unsigned char> TBuf;

    class TBitBuf {
    private:
        //TBuf Buf;
        //i64 BitsCount;
        std::vector<bool> Bits;
    public:
        TBitBuf();

        void WriteByte(unsigned char symbol);
        void WriteBit(bool bit);
        void Clear();
        size_t Size() const;
        size_t Empty() const;
        const std::vector<bool> &GetBits() const;
    };
} // namespace ystd
