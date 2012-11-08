#include <iostream>
#include <exception>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>

#include <zip.h>

using namespace std;
using namespace ystd;

typedef unsigned int ui32;
typedef long long i64;

static i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

static void Test() {
    vector<unsigned char> data;
    Zip("book.fb2", data);
    //Unzip("book.fb2.zip", "book_unzipped.fb2");
}

int main( int argc, char** argv ) {
    try {
        Test();
    } catch (const TZipException &xcp) {
        cout << "A TZipException occured in main routine: " << xcp.what() << endl;
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
