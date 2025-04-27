#pragma once
#include <iostream>

class VectorLong {
private:
    long* data;
    int size;
    int codeError;
    static int count;

public:
    VectorLong() : data(nullptr), size(0), codeError(0) { count++; }

    VectorLong(int size) : size(size), codeError(0) {
        data = new(std::nothrow) long[size];
        if (!data) {
            codeError = 1;
        }
        else {
            for (int i = 0; i < size; i++) data[i] = 0;
        }
        count++;
    }

    VectorLong(const VectorLong& other) : size(other.size), codeError(other.codeError) {
        data = new(std::nothrow) long[size];
        if (!data) {
            codeError = 1;
        }
        else {
            for (int i = 0; i < size; i++) data[i] = other.data[i];
        }
        count++;
    }

    ~VectorLong() {
        delete[] data;
        count--;
    }

    long& operator[](int index) {
        if (index < 0 || index >= size) {
            codeError = 2;
            return data[size - 1];
        }
        return data[index];
    }

    VectorLong& operator=(const VectorLong& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new(std::nothrow) long[size];
            if (!data) {
                codeError = 1;
            }
            else {
                for (int i = 0; i < size; i++) data[i] = other.data[i];
            }
            codeError = other.codeError;
        }
        return *this;
    }

    int getSize() const { return size; }
    int getCodeError() const { return codeError; }

    static int getCount() { return count; }

    friend std::ostream& operator<<(std::ostream& os, const VectorLong& v) {
        for (int i = 0; i < v.size; ++i) os << v.data[i] << " ";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, VectorLong& v) {
        for (int i = 0; i < v.size; ++i) is >> v.data[i];
        return is;
    }
};

int VectorLong::count = 0;
