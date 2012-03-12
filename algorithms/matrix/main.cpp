#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>
using namespace std;

typedef unsigned int ui32;

template<typename T, int ROWS, int COLUMNS>
class TMatrix {
private:
    T Elems[ROWS][COLUMNS];

    void Zero() {
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLUMNS; ++j)
                Elems[i][j] = T();
    }

public:
    TMatrix() {
        Zero();
    }

    //template<typename U>
    //TMatrix(const TMatrix<U, ROWS, COLUMNS> &other) {
    TMatrix(const TMatrix &other) {
        *this = other;
    }

    //template<typename U>
    //TMatrix<T, ROWS, COLUMNS>& operator=(const TMatrix<U, ROWS, COLUMNS> &other) {
    TMatrix& operator=(const TMatrix &other) {
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLUMNS; ++j)
                Elems[i][j] = other.Elems[i][j];
                //Elems[i][j] = other.Get(i, j);
        return *this;
    }

    const T& operator()(int i, int j) const {
        return Elems[i][j];
    }

    T& operator()(int i, int j) {
        return Elems[i][j];
    }

    TMatrix operator+(const TMatrix &other) {
        TMatrix res;
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLUMNS; ++j)
                res.Elems[i][j] = this->Elems[i][j] + other.Elems[i][j];
        return res;
    }

    TMatrix operator-(const TMatrix &other) {
        TMatrix res;
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLUMNS; ++j)
                res.Elems[i][j] = this->Elems[i][j] - other.Elems[i][j];
        return res;
    }

    template<int OTHER_COLUMNS>
    TMatrix<T, ROWS, OTHER_COLUMNS> operator*(const TMatrix<T, COLUMNS, OTHER_COLUMNS> &other) {
        TMatrix<T, ROWS, OTHER_COLUMNS> res;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < OTHER_COLUMNS; ++j) {
                T tmp = T();
                for (int k = 0; k < COLUMNS; ++k) {
                    tmp += this->Elems[i][k] * other(k, j);
                }
                res(i, j) = tmp;
            }
        }
        return res;
    }

    template<typename pT, int pROWS, int pCOLUMNS>
    friend ostream &operator<<(ostream &ous, const TMatrix<pT, pROWS, pCOLUMNS> &mx);
};

template<typename T, int ROWS, int COLUMNS>
ostream &operator<<(ostream &ous, const TMatrix<T, ROWS, COLUMNS> &mx) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j)
            ous << mx.Elems[i][j] << "\t";
        ous << "\n";
    }
    return ous;
}

int main( int argc, char** argv ) {
    try {
        TMatrix<int, 2, 3> m1;
        TMatrix<int, 3, 4> m2;

        // m1
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                m1(i, j) = i + j;

        // m2
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 4; ++j)
                m2(i, j) = i - j;

        cout << m1 << endl
            << m2 << endl;

        TMatrix<int, 2, 4> m3 = m1 * m2;
        cout << m3 << endl;
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
