#include <iostream>
#include <exception>

using namespace std;

int main( int argc, char** argv ) {
    try {
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
