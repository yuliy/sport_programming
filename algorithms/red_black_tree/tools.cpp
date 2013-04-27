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

//
// TFoo
//

int TFoo::Created = 0;
int TFoo::Deleted = 0;

TFoo::TFoo() {
    Value = int();
    ++Created;
}

TFoo::TFoo(const TFoo& other) {
    Value = other.Value;
    ++Created;
}

TFoo::TFoo(int value) {
    Value = value;
    ++Created;
}

TFoo &TFoo::operator=(const TFoo& other) {
    Value = other.Value;
    return *this;
}

TFoo::~TFoo() {
    ++Deleted;
}

void TFoo::PrintStats() {
    cout << "TFoo::Created = " << TFoo::Created << endl
        << "TFoo::Deleeted = " << TFoo::Deleted << endl;
}

} // namespace ystd
