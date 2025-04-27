#pragma once
#include <iostream>
#include <cmath>
#include <ctime>


class Matrix {
private:
    long** data;
    int rows, cols;
    int error_state;
    static int object_count;

public:
    Matrix() : Matrix(5, 5, 0) {}

    Matrix(int n) : Matrix(n, n, 0) {}

    Matrix(int n, int m, long value = 0) : rows(n), cols(m), error_state(0) {
        allocateMatrix();
        initializeMatrix(value);
        object_count++;
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), error_state(other.error_state) {
        allocateMatrix();
        copyData(other);
        object_count++;
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;
        freeMatrix();
        rows = other.rows;
        cols = other.cols;
        error_state = other.error_state;
        allocateMatrix();
        copyData(other);
        return *this;
    }

    ~Matrix() {
        freeMatrix();
        object_count--;
    }

    void setElement(int i, int j, long value = 0) {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
            data[i][j] = value;
        else {
            error_state = 1; 
            std::cerr << "Error: Index out of bounds!\n";
        }
    }

    long getElement(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            std::cerr << "Error: Index out of bounds!\n";
            return 0;
        }
        return data[i][j];
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                std::cout << data[i][j] << " ";
            std::cout << "\n";
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Error: Cannot add matrices of different sizes!");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = this->data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Error: Cannot subtract matrices of different sizes!");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = this->data[i][j] - other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::runtime_error("Error: Cannot multiply matrices due to incompatible dimensions!");
        }
        Matrix result(rows, other.cols, 0);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    Matrix operator/(long scalar) const {
        if (scalar == 0) {
            throw std::runtime_error("Error: Division by zero!");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = this->data[i][j] / scalar;
        return result;
    }

    bool operator==(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) return false;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (data[i][j] != other.data[i][j]) return false;
        return true;
    }

    bool operator!=(const Matrix& other) const { return !(*this == other); }
    bool operator<(const Matrix& other) const { return rows * cols < other.rows * other.cols; }
    bool operator>(const Matrix& other) const { return rows * cols > other.rows * other.cols; }

    static int getObjectCount() { return object_count; }

private:
    void allocateMatrix() {
        data = new long* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new long[cols];
        }
    }

    void initializeMatrix(long value) {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = value;
    }

    void copyData(const Matrix& other) {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
    }

    void freeMatrix() {
        if (data) {
            for (int i = 0; i < rows; ++i)
                delete[] data[i];
            delete[] data;
            data = nullptr;
        }
    }
};