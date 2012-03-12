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

public:
    TMatrix() {
        Fill(T());
    }

    TMatrix(const TMatrix &other) {
        *this = other;
    }

    TMatrix& operator=(const TMatrix &other) {
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLUMNS; ++j)
                Elems[i][j] = other.Elems[i][j];
        return *this;
    }

    int Rows() const {
        return ROWS;
    }

    int Columns() const {
        return COLUMNS;
    }

    void Fill(const T &val) {
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLUMNS; ++j)
                Elems[i][j] = val;
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

    TMatrix operator*(T scalar) {
        TMatrix res;
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLUMNS; ++j)
                res.Elems[i][j] = this->Elems[i][j] * scalar;
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

    bool operator==(const TMatrix &other) {
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLUMNS; ++j)
                if (Elems[i][j] != other.Elems[i][j])
                    return false;
        return true;
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

template<typename T, int N, int M, int K>
TMatrix<T, N, K> ShtrassenMultiply(const TMatrix<T, N, M> &a, const TMatrix<T, M, K> &b) {
    //
}

template<int R, int C>
TMatrix<int, R, C> CreateRandomMatrix() {
    TMatrix<int, R, C> res;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            res(i, j) = rand() % 1000;
    return res;
}

static void Test1() {
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
}

static void Test2() {
    TMatrix<int, 10, 10> m = CreateRandomMatrix<10, 10>();
    cout << m << endl;
}

int main( int argc, char** argv ) {
    try {
        //srand( time(NULL) );
        Test2();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
