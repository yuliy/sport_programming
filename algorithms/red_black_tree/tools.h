#pragma once

namespace ystd {

typedef unsigned int ui32;
typedef long long i64;

i64 GetTickCount();

/**
  * Usefull class for measuring time intervals in seconds
  */
class TTimePrinter {
    i64 Start;
public:
    TTimePrinter();
    void PrintTime() const;
    double GetTime() const;
};

/**
  * Usefull class for simple search of memory leaks
  */
struct TFoo {
    int Value;
    static int Created;
    static int Deleted;

    TFoo();
    TFoo(const TFoo& other);
    explicit TFoo(int value);
    TFoo &operator=(const TFoo& other);
    ~TFoo();

    bool operator<(const TFoo &other) const;

    static void PrintStats();
};

} // namespace ystd
