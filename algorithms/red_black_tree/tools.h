#pragma once

namespace ystd {

typedef unsigned int ui32;
typedef long long i64;

i64 GetTickCount();

class TTimePrinter {
    i64 Start;
public:
    TTimePrinter();
    void PrintTime() const;
    double GetTime() const;
};

} // namespace ystd
