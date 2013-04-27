#include "tools.h"

#include <time.h>
#include <iostream>

using namespace std;

namespace ystd {

i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

TTimePrinter::TTimePrinter()
    : Start(GetTickCount()) {
}

void TTimePrinter::PrintTime() const {
    cout << "\tTime: " << GetTime() << " sec" << endl;
}

double TTimePrinter::GetTime() const {
    return (GetTickCount() - Start) * 0.001;
}

} // namespace ystd
