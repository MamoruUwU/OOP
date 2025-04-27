#pragma once
#include <iostream>
#include <cmath>


class Vector {
private:
    double elements[3];
    int state;
    static int objectCount;

public:

    Vector() : elements{ 0, 0, 0 }, state(0) {
        objectCount++;
    }

    Vector(double value) : elements{ value, value, value }, state(0) {
        objectCount++;
    }

    Vector(double x, double y, double z) : elements{ x, y, z }, state(0) {
        objectCount++;
    }

    Vector(const double* arr) {
        if (arr) {
            for (int i = 0; i < 3; i++) {
                elements[i] = arr[i];
            }
            state = 0;
        }
        else {
            state = 1;
            elements[0] = elements[1] = elements[2] = 0;
        }
        objectCount++;
    }

    ~Vector() {
        std::cout << "Vector destroyed. State: " << state << std::endl;
        objectCount--;
    }

    void setValues(double value = 0) {
        for (int i = 0; i < 3; i++) {
            elements[i] = value;
        }
    }

    double getElement(int index) const {
        if (index >= 0 && index < 3) {
            return elements[index];
        }
        else {
            return NAN; 
        }
    }

    void print() const {
        std::cout << "Vector: (" << elements[0] << ", " << elements[1] << ", " << elements[2] << ")\n";
    }

    Vector add(const Vector& other) const {
        return Vector(elements[0] + other.elements[0], elements[1] + other.elements[1], elements[2] + other.elements[2]);
    }

    Vector subtract(const Vector& other) const {
        return Vector(elements[0] - other.elements[0], elements[1] - other.elements[1], elements[2] - other.elements[2]);
    }

    Vector crossProduct(const Vector& other) const {
        return Vector(
            elements[1] * other.elements[2] - elements[2] * other.elements[1],
            elements[2] * other.elements[0] - elements[0] * other.elements[2],
            elements[0] * other.elements[1] - elements[1] * other.elements[0]
        );
    }

    void divide(short divisor) {
        if (divisor == 0) {
            state = 2;
            return;
        }
        for (int i = 0; i < 3; i++) {
            elements[i] /= divisor;
        }
    }

    bool isGreaterThan(const Vector& other) const {
        return magnitude() > other.magnitude();
    }

    bool isLessThan(const Vector& other) const {
        return magnitude() < other.magnitude();
    }

    bool isEqualTo(const Vector& other) const {
        return magnitude() == other.magnitude();
    }

    int getState() const {
        return state;
    }

    static int getObjectCount() {
        return objectCount;
    }

private:
    double magnitude() const {
        return sqrt(elements[0] * elements[0] + elements[1] * elements[1] + elements[2] * elements[2]);
    }
};