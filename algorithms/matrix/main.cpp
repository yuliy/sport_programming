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

template<typename T, int COLUMNS, int ROWS>
class TMatrix {
private:
    T Elems[COLUMNS][ROWS];

    void Zero() {
        for (int i = 0; i < COLUMNS; ++i)
            for (int j = 0; j < ROWS; ++j)
                Elems[i][j] = T();
    }

public:
    TMatrix() {
        Zero();
    }

    //template<typename U>
    //TMatrix(const TMatrix<U, COLUMNS, ROWS> &other) {
    TMatrix(const TMatrix &other) {
        *this = other;
    }

    //template<typename U>
    //TMatrix<T, COLUMNS, ROWS>& operator=(const TMatrix<U, COLUMNS, ROWS> &other) {
    TMatrix& operator=(const TMatrix &other) {
        for (int i = 0; i < COLUMNS; ++i)
            for (int j = 0; j < ROWS; ++j)
                Elems[i][j] = other.Elems[i][j];
                //Elems[i][j] = other.Get(i, j);
        return *this;
    }

    void Set(int i, int j, const T& elem) {
        Elems[i][j] = elem;
    }

    const T& Get(int i, int j) const {
        return Elems[i][j];
    }

    TMatrix operator+(const TMatrix &other) {
        TMatrix res;
        for (int i = 0; i < COLUMNS; ++i)
            for (int j = 0; j < ROWS; ++j)
                res.Elems[i][j] = this->Elems[i][j] + other.Elems[i][j];
        return res;
    }

    TMatrix operator-(const TMatrix &other) {
        TMatrix res;
        for (int i = 0; i < COLUMNS; ++i)
            for (int j = 0; j < ROWS; ++j)
                res.Elems[i][j] = this->Elems[i][j] - other.Elems[i][j];
        return res;
    }

    template<int OTHER_ROWS>
    TMatrix<T, COLUMNS, OTHER_ROWS> operator*(const TMatrix<T, ROWS, OTHER_ROWS> &other) {
        TMatrix<T, COLUMNS, OTHER_ROWS> res;
        for (int i = 0; i < COLUMNS; ++i) {
            for (int j = 0; j < ROWS; ++j) {
                T tmp();
                for (int k = 0; k < OTHER_ROWS; ++k) {
                    tmp += this->Elems[i][j] * other.Get(j, k);
                }
                res.Set(i, j, tmp);
            }
        }
        return res;
    }

    template<typename pT, int pCOLUMNS, int pROWS>
    friend ostream &operator<<(ostream &ous, const TMatrix<pT, pCOLUMNS, pROWS> &mx);
};

template<typename T, int COLUMNS, int ROWS>
ostream &operator<<(ostream &ous, const TMatrix<T, COLUMNS, ROWS> &mx) {
    for (int i = 0; i < COLUMNS; ++i) {
        for (int j = 0; j < ROWS; ++j)
            ous << mx.Elems[i][j] << "\t";
        ous << "\n";
    }
    return ous;
}

int main( int argc, char** argv ) {
    try {
        TMatrix<int, 3, 3> m1;
        TMatrix<int, 3, 3> m2(m1);
        cout << m1 << endl
             << m2 << endl;
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
