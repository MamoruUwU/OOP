#pragma once
#include "VectorLong.h"

class MatrixLong {
protected:
    VectorLong* LongArray;
    int n, size;
    int codeError;
    static int num_matrix;

public:
    MatrixLong() : LongArray(nullptr), n(0), size(0), codeError(0) { num_matrix++; }

    MatrixLong(int s) : n(s), size(s), codeError(0) {
        LongArray = new VectorLong[n];
        for (int i = 0; i < n; i++) {
            LongArray[i] = VectorLong(size);
            LongArray[i][i] = 1;
        }
        num_matrix++;
    }

    MatrixLong(int rows, int cols) : n(rows), size(cols), codeError(0) {
        LongArray = new(std::nothrow) VectorLong[n];
        if (!LongArray) {
            codeError = 1;
            return;
        }
        for (int i = 0; i < n; ++i)
            LongArray[i] = VectorLong(size);
        num_matrix++;
    }

    MatrixLong(int rows, int cols, long value) : n(rows), size(cols), codeError(0) {
        LongArray = new(std::nothrow) VectorLong[n];
        if (!LongArray) {
            codeError = 1;
            return;
        }
        for (int i = 0; i < n; ++i) {
            LongArray[i] = VectorLong(size);
            for (int j = 0; j < size; ++j)
                LongArray[i][j] = value;
        }
        num_matrix++;
    }

    MatrixLong(const MatrixLong& other) : n(other.n), size(other.size), codeError(other.codeError) {
        LongArray = new VectorLong[n];
        for (int i = 0; i < n; ++i)
            LongArray[i] = other.LongArray[i];
        num_matrix++;
    }

    ~MatrixLong() {
        delete[] LongArray;
        num_matrix--;
    }

    int getRows() const { return n; }
    int getCols() const { return size; }
    int getCodeError() const { return codeError; }

    MatrixLong& operator=(const MatrixLong& other) {
        if (this != &other) {
            delete[] LongArray;
            n = other.n;
            size = other.size;
            codeError = other.codeError;
            LongArray = new VectorLong[n];
            for (int i = 0; i < n; ++i)
                LongArray[i] = other.LongArray[i];
        }
        return *this;
    }

    MatrixLong operator+(const MatrixLong& other) const {
        MatrixLong result(n, size);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < size; j++)
                result.LongArray[i][j] = LongArray[i][j] + other.LongArray[i][j];
        return result;
    }

    MatrixLong operator+(long scalar) const {
        MatrixLong result(n, size);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < size; j++)
                result.LongArray[i][j] = LongArray[i][j] + scalar;
        return result;
    }

    MatrixLong operator*(const MatrixLong& other) const {
        if (size != other.n) {
            MatrixLong res;
            res.codeError = 3;
            return res;
        }
        MatrixLong result(n, other.size);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < other.size; ++j)
                for (int k = 0; k < size; ++k)
                    result.LongArray[i][j] += LongArray[i][k] * other.LongArray[k][j];
        return result;
    }

    MatrixLong operator*(long scalar) const {
        MatrixLong result(n, size);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < size; j++)
                result.LongArray[i][j] = LongArray[i][j] * scalar;
        return result;
    }

    VectorLong& operator[](int index) {
        if (index < 0 || index >= n) {
            codeError = 2;
            return LongArray[n - 1];
        }
        return LongArray[index];
    }

    MatrixLong operator-() const {
        MatrixLong result(n, size);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < size; ++j)
                result.LongArray[i][j] = -LongArray[i][j];
        return result;
    }

    MatrixLong& operator++() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < size; ++j)
                LongArray[i][j]++;
        return *this;
    }

    MatrixLong operator++(int) {
        MatrixLong tmp(*this);
        ++(*this);
        return tmp;
    }

    MatrixLong& operator--() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < size; ++j)
                LongArray[i][j]--;
        return *this;
    }

    MatrixLong operator--(int) {
        MatrixLong tmp(*this);
        --(*this);
        return tmp;
    }

    bool operator!() const {
        return !(n && size);
    }

    MatrixLong operator~() const {
        MatrixLong result(n, size);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < size; j++)
                result.LongArray[i][j] = ~LongArray[i][j];
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const MatrixLong& m) {
        for (int i = 0; i < m.n; ++i) {
            os << m.LongArray[i] << "\n";
        }
        return os;
    }

    static int getMatrixCount() { return num_matrix; }
};

int MatrixLong::num_matrix = 0;
