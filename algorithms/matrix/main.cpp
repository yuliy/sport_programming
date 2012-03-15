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
typedef long long i64;

i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

template<typename T, int ROWS, int COLUMNS>
class TMatrix {
private:
    //T Elems[ROWS][COLUMNS];
    typedef vector< vector<T> > TElems;
    TElems Elems;
private:
    void AllocateMemory() {
        vector<int> tmp(COLUMNS);
        for (int i = 0; i < ROWS; ++i)
            Elems.push_back(tmp);
    }
public:
    TMatrix() {
        AllocateMemory();
        //Fill(T());
    }

    TMatrix(const TMatrix &other) {
        Elems = other.Elems;
    }

    TMatrix& operator=(const TMatrix &other) {
        Elems = other.Elems;
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

    TMatrix operator+(const TMatrix &other) const {
        TMatrix res;
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLUMNS; ++j)
                res.Elems[i][j] = this->Elems[i][j] + other.Elems[i][j];
        return res;
    }

    TMatrix operator-(const TMatrix &other) const {
        TMatrix res;
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLUMNS; ++j)
                res.Elems[i][j] = this->Elems[i][j] - other.Elems[i][j];
        return res;
    }

    TMatrix operator*(T scalar) const {
        TMatrix res;
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLUMNS; ++j)
                res.Elems[i][j] = this->Elems[i][j] * scalar;
        return res;
    }

    template<int OTHER_COLUMNS>
    TMatrix<T, ROWS, OTHER_COLUMNS> operator*(const TMatrix<T, COLUMNS, OTHER_COLUMNS> &other) const {
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

    bool operator==(const TMatrix &other) const {
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

template<typename T, int N>
void Split(const TMatrix<T, N, N> &m,
            TMatrix<T, N/2, N/2> &a,
            TMatrix<T, N/2, N/2> &b,
            TMatrix<T, N/2, N/2> &c,
            TMatrix<T, N/2, N/2> &d) {
    const int n = N >> 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a(i, j) = m(i, j);
            b(i, j) = m(i, j + n);
            c(i, j) = m(i + n, j);
            d(i, j) = m(i + n, j + n);
        }
    }
}

template<typename T, int N>
void Join(TMatrix<T, N, N> &res,
            const TMatrix<T, N/2, N/2> &r,
            const TMatrix<T, N/2, N/2> &s,
            const TMatrix<T, N/2, N/2> &t,
            const TMatrix<T, N/2, N/2> &u) {
    const int n = N >> 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res(i, j)         = r(i, j);
            res(i, j + n)     = s(i, j);
            res(i + n, j)     = t(i, j);
            res(i + n, j + n) = u(i, j);
        }
    }
}

template<typename T, int N>
TMatrix<T, N, N> ShtrassenMultiply(const TMatrix<T, N, N> &A, const TMatrix<T, N, N> &B) {
    if (N <= 128)
        return A * B;

    const int n = N >> 1;
    typedef TMatrix<T, n, n> TMx;

    TMx a, b, c, d;
    TMx e, f, g, h;
    Split(A, a, b, c, d);
    Split(B, e, f, g, h);

/*
    cout << "A:" << endl << A << endl << endl
        << "a:" << endl << a << endl << endl
        << "b:" << endl << b << endl << endl
        << "c:" << endl << c << endl << endl
        << "d:" << endl << d << endl << endl;
        */

    const TMx P1 = ShtrassenMultiply(a, f - h);
    const TMx P2 = ShtrassenMultiply(a + b, h);
    const TMx P3 = ShtrassenMultiply(c + d, e);
    const TMx P4 = ShtrassenMultiply(d, g - e);
    const TMx P5 = ShtrassenMultiply(a + d, e + h);
    const TMx P6 = ShtrassenMultiply(b - d, g + h);
    const TMx P7 = ShtrassenMultiply(a - c, e + f);

    const TMx r = P5 + P4 - P2 + P6;
    const TMx s = P1 + P2;
    const TMx t = P3 + P4;
    const TMx u = P5 + P1 - P3 - P7;

    TMatrix<T, N, N> res;
    Join(res, r, s, t, u);
    return res;
}

template<int R, int C>
TMatrix<int, R, C> CreateRandomMatrix() {
    TMatrix<int, R, C> res;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            res(i, j) = rand() % 100;
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
    cout << "Generating random input matrices..." << endl;
    const int N = 2048;
    typedef TMatrix<int, N, N> TMat;
    const TMat m1 = CreateRandomMatrix<N, N>();
    const TMat m2 = CreateRandomMatrix<N, N>();

    cout << "Running calculations for N=" << N << " ..." << endl;
    const i64 start1 = GetTickCount();
    const TMat r1 = m1 * m2;
    const i64 time1 = GetTickCount() - start1;
    cout << "\ttime1: " << time1 << "ms" << endl;

    const i64 start2 = GetTickCount();
    const TMat r2 = ShtrassenMultiply(m1, m2);
    const i64 time2 = GetTickCount() - start2;
    cout << "\ttime2: " << time2 << "ms" << endl;

    if (r1 == r2) {
        cout << "Correct: YES" << endl;
    } else {
        cout << "Correct: NO! There are errors!" << endl;
    }

    /*
    cout << "Matrix 1:" << endl << m1 << endl << endl
        << "Matrix 2:" << endl << m2 << endl << endl
        << "Algorithm 1 result:" << endl << r1 << endl << endl
        << "Algorithm 2 result:" << endl << r2 << endl << endl;
        */
}

int main( int argc, char** argv ) {
    try {
        //srand( time(NULL) );
        //Test1();
        Test2();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
