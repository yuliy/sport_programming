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

class TMatrixException {
private:
    string Descr;
public:
    TMatrixException(const char *descr)
        : Descr(descr) {
    }

    TMatrixException(const string &descr)
        : Descr(descr) {
    }

    const char * what() const throw() {
        return Descr.c_str();
    }
};

template<typename T>
class TMatrix {
private:
    typedef vector< vector<T> > TElems;
    TElems Elems;
    int Rows;
    int Cols;
private:
    void AllocateMemory(int rows, int cols) {
        vector<int> tmp(rows);
        for (int i = 0; i < cols; ++i)
            Elems.push_back(tmp);
    }
private:
    TMatrix();
public:
    TMatrix(int rows, int cols)
        : Rows(rows)
        , Cols(cols) {
        AllocateMemory(rows, cols);
    }

    TMatrix(const TMatrix &other) {
        Elems = other.Elems;
        Rows = other.Rows;
        Cols = other.Cols;
    }

    TMatrix& operator=(const TMatrix &other) {
        if (Rows != other.Rows)
            throw TMatrixException("Error in TMatrix::operator=(): Rows should be equal to other.Rows!");
        if (Cols != other.Cols)
            throw TMatrixException("Error in TMatrix::operator=(): Cols should be equal to other.Cols!");

        Elems = other.Elems;
        Rows = other.Rows;
        Cols = other.Cols;
        return *this;
    }

    int GetRows() const {
        return Rows;
    }

    int GetCols() const {
        return Cols;
    }

    void Fill(const T &val) {
        for (int i = 0; i < Rows; ++i)
            for (int j = 0; j < Cols; ++j)
                Elems[i][j] = val;
    }

    const T& operator()(int i, int j) const {
        return Elems[i][j];
    }

    T& operator()(int i, int j) {
        return Elems[i][j];
    }

    TMatrix operator+(const TMatrix &other) const {
        if (Rows != other.Rows)
            throw TMatrixException("Error in TMatrix::operator+(): Rows should be equal to other.Rows!");
        if (Cols != other.Cols)
            throw TMatrixException("Error in TMatrix::operator+(): Cols should be equal to other.Cols!");

        TMatrix res(Rows, Cols);
        for (int i = 0; i < Rows; ++i)
            for (int j = 0; j < Cols; ++j)
                res.Elems[i][j] = this->Elems[i][j] + other.Elems[i][j];
        return res;
    }

    TMatrix operator-(const TMatrix &other) const {
        if (Rows != other.Rows)
            throw TMatrixException("Error in TMatrix::operator-(): Rows should be equal to other.Rows!");
        if (Cols != other.Cols)
            throw TMatrixException("Error in TMatrix::operator-(): Cols should be equal to other.Cols!");

        TMatrix res(Rows, Cols);
        for (int i = 0; i < Rows; ++i)
            for (int j = 0; j < Cols; ++j)
                res.Elems[i][j] = this->Elems[i][j] - other.Elems[i][j];
        return res;
    }

    TMatrix operator*(T scalar) const {
        TMatrix res(Rows, Cols);
        for (int i = 0; i < Rows; ++i)
            for (int j = 0; j < Cols; ++j)
                res.Elems[i][j] = this->Elems[i][j] * scalar;
        return res;
    }

    TMatrix operator*(const TMatrix &other) const {
        if (Cols != other.Rows)
            throw TMatrixException("Error in TMatrix::operator*: Cols should be equal to other.Rows!");

        TMatrix res(Rows, other.Cols);
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < other.Cols; ++j) {
                T tmp = T();
                for (int k = 0; k < Cols; ++k) {
                    tmp += this->Elems[i][k] * other(k, j);
                }
                res(i, j) = tmp;
            }
        }
        return res;
    }

    bool operator==(const TMatrix &other) const {
        return Elems == other.Elems;
    }

    template<typename U>
    friend ostream &operator<<(ostream &ous, const TMatrix<U> &mx);
};

template<typename T>
ostream &operator<<(ostream &ous, const TMatrix<T> &mx) {
    const int rows = mx.GetRows();
    const int cols = mx.GetCols();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            ous << mx.Elems[i][j] << "\t";
        ous << "\n";
    }
    return ous;
}

template<typename T>
void Split(const TMatrix<T> &m,
            TMatrix<T> &a,
            TMatrix<T> &b,
            TMatrix<T> &c,
            TMatrix<T> &d) {
    const int n = a.GetRows();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a(i, j) = m(i, j);
            b(i, j) = m(i, j + n);
            c(i, j) = m(i + n, j);
            d(i, j) = m(i + n, j + n);
        }
    }
}

template<typename T>
void Join(TMatrix<T> &res,
            const TMatrix<T> &r,
            const TMatrix<T> &s,
            const TMatrix<T> &t,
            const TMatrix<T> &u) {
    const int n = r.GetRows();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res(i, j)         = r(i, j);
            res(i, j + n)     = s(i, j);
            res(i + n, j)     = t(i, j);
            res(i + n, j + n) = u(i, j);
        }
    }
}

template<typename T>
TMatrix<T> ShtrassenMultiply(const TMatrix<T> &A, const TMatrix<T> &B) {
    const int N = A.GetRows();
    if (N <= 128)
        return A * B;

    const int n = N >> 1;
    typedef TMatrix<T> TMx;

    TMx a(n, n), b(n, n), c(n, n), d(n, n);
    TMx e(n, n), f(n, n), g(n, n), h(n, n);
    Split(A, a, b, c, d);
    Split(B, e, f, g, h);
    
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

    TMatrix<T> res(N, N);
    Join(res, r, s, t, u);
    return res;
}

TMatrix<int> CreateRandomMatrix(int rows, int cols) {
    TMatrix<int> res(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            res(i, j) = rand() % 100;
    return res;
}

static void Test1() {
    TMatrix<int> m1(2, 3);
    TMatrix<int> m2(3, 4);

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

    TMatrix<int> m3 = m1 * m2;
    cout << m3 << endl;
}

static void Test2(int N) {
    cout << "---------------------------------------------" << endl;
    //cout << "Generating random input matrices..." << endl;
    //const int N = 16;
    typedef TMatrix<int> TMat;
    const TMat m1 = CreateRandomMatrix(N, N);
    const TMat m2 = CreateRandomMatrix(N, N);

    cout << "N=" << N << endl;
    const i64 start1 = GetTickCount();
    const TMat r1 = m1 * m2;
    const i64 time1 = GetTickCount() - start1;
    cout << "\ttime1: " << time1 << "ms" << endl;

    const i64 start2 = GetTickCount();
    const TMat r2 = ShtrassenMultiply(m1, m2);
    const i64 time2 = GetTickCount() - start2;
    cout << "\ttime2: " << time2 << "ms" << endl;

    if (r1 == r2) {
        //cout << "Correct: YES" << endl;
    } else {
        //cout << "Correct: NO! There are errors!" << endl;
    }

    //cout << "Matrix 1:" << endl << m1 << endl << endl
    //    << "Matrix 2:" << endl << m2 << endl << endl
    //    << "Algorithm 1 result:" << endl << r1 << endl << endl
    //    << "Algorithm 2 result:" << endl << r2 << endl << endl;
}

int main( int argc, char** argv ) {
    try {
        //srand( time(NULL) );
        //Test1();
        for (int i = 2; i <= 1024; i <<= 1)
            Test2(i);
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
