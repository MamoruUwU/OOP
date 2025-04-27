#pragma once
#include <iostream>
#include <cmath>

enum class State {
    OK,
    NULL_POINTER,
    DIVIDE_BY_ZERO,
    OUT_OF_RANGE
};

class Vector3D {
private:
    double x, y, z;
    State state;
    static int objectCount;

public:

    Vector3D() : x(0), y(0), z(0), state(State::OK) { objectCount++; }

    Vector3D(double val) : x(val), y(val), z(val), state(State::OK) { objectCount++; }

    Vector3D(const double* ptr) {
        if (ptr != nullptr) {
            x = ptr[0]; y = ptr[1]; z = ptr[2];
            state = State::OK;
        }
        else {
            x = y = z = 0;
            state = State::NULL_POINTER;
        }
        objectCount++;
    }

    ~Vector3D() {
        std::cout << "Destructor: x=" << x << ", y=" << y << ", z=" << z
            << ", state: " << static_cast<int>(state) << "\n";
        objectCount--;
    }

    Vector3D& operator++() { x += 1; y += 1; z += 1; return *this; }
    Vector3D operator++(int) { Vector3D tmp = *this; ++(*this); return tmp; } 

    Vector3D& operator--() { x -= 1; y -= 1; z -= 1; return *this; }
    Vector3D operator--(int) { Vector3D tmp = *this; --(*this); return tmp; }

    bool operator!() const { return x == 0 && y == 0 && z == 0; }

    Vector3D operator~() const { return Vector3D(-y, x, z); }

    Vector3D operator-() const { return Vector3D(-x, -y, -z); }

    Vector3D(double x, double y, double z) : x(x), y(y), z(z), state(State::OK) {
        objectCount++;
    }

    Vector3D& operator=(const Vector3D& other) {
        if (this != &other) {
            x = other.x; y = other.y; z = other.z;
            state = other.state;
        }
        return *this;
    }

    Vector3D& operator+=(const Vector3D& other) {
        x += other.x; y += other.y; z += other.z; return *this;
    }

    Vector3D& operator-=(const Vector3D& other) {
        x -= other.x; y -= other.y; z -= other.z; return *this;
    }

    Vector3D& operator*=(double scalar) {
        x *= scalar; y *= scalar; z *= scalar; return *this;
    }

    Vector3D& operator/=(double scalar) {
        if (scalar == 0) {
            state = State::DIVIDE_BY_ZERO;
        }
        else {
            x /= scalar; y /= scalar; z /= scalar;
        }
        return *this;
    }

    Vector3D& operator&=(const Vector3D& other) {
        double newX = y * other.z - z * other.y;
        double newY = z * other.x - x * other.z;
        double newZ = x * other.y - y * other.x;
        x = newX; y = newY; z = newZ;
        return *this;
    }

    Vector3D& operator%=(int val) {
        if (val == 0) {
            state = State::DIVIDE_BY_ZERO;
        }
        else {
            x = static_cast<int>(x) % val;
            y = static_cast<int>(y) % val;
            z = static_cast<int>(z) % val;
        }
        return *this;
    }

    Vector3D operator+(const Vector3D& other) const { return Vector3D(x + other.x, y + other.y, z + other.z); }
    Vector3D operator-(const Vector3D& other) const { return Vector3D(x - other.x, y - other.y, z - other.z); }
    Vector3D operator*(double scalar) const { return Vector3D(x * scalar, y * scalar, z * scalar); }
    Vector3D operator/(double scalar) const {
        if (scalar == 0) {
            Vector3D tmp(*this);
            tmp.state = State::DIVIDE_BY_ZERO;
            return tmp;
        }
        return Vector3D(x / scalar, y / scalar, z / scalar);
    }
    Vector3D operator%(int val) const {
        if (val == 0) {
            Vector3D tmp(*this);
            tmp.state = State::DIVIDE_BY_ZERO;
            return tmp;
        }
        return Vector3D(static_cast<int>(x) % val,
            static_cast<int>(y) % val,
            static_cast<int>(z) % val);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
        return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    }

    friend std::istream& operator>>(std::istream& is, Vector3D& v) {
        return is >> v.x >> v.y >> v.z;
    }

    bool operator==(const Vector3D& other) const { return x == other.x && y == other.y && z == other.z; }
    bool operator!=(const Vector3D& other) const { return !(*this == other); }

    bool operator>(const Vector3D& other) const { return x > other.x && y > other.y && z > other.z; }
    bool operator>=(const Vector3D& other) const { return x >= other.x && y >= other.y && z >= other.z; }
    bool operator<(const Vector3D& other) const { return x < other.x && y < other.y && z < other.z; }
    bool operator<=(const Vector3D& other) const { return x <= other.x && y <= other.y && z <= other.z; }

    double& operator[](int index) {
        switch (index) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: state = State::OUT_OF_RANGE; return z;
        }
    }

    void operator()() const {
        std::cout << "Vector: (" << x << ", " << y << ", " << z << ")\n";
    }

    State getState() const { return state; }

    static int getObjectCount() { return objectCount; }
};

int Vector3D::objectCount = 0;
