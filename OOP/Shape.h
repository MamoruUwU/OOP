#pragma once
#include <iostream>

constexpr auto M_PI = 3.14159265358979323846;

class Shape {
protected:
    std::string name;

public:
    Shape(const std::string& n = "Shape") : name(n) {}
    virtual ~Shape() {}

    virtual void print(std::ostream& os) const {
        os << "Shape: " << name;
    }

    virtual void input(std::istream& is) {
        std::cout << "Enter shape name: ";
        is >> name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Shape& s) {
        s.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Shape& s) {
        s.input(is);
        return is;
    }
};

class Circle : virtual public Shape {
protected:
    double radius;

public:
    Circle(double r = 0.0) : Shape("Circle"), radius(r) {}
    Circle(const std::string& n, double r) : Shape(n), radius(r) {}
    virtual ~Circle() {}

    virtual void print(std::ostream& os) const override {
        Shape::print(os);
        os << ", Radius: " << radius;
    }

    virtual void input(std::istream& is) override {
        Shape::input(is);
        std::cout << "Enter radius: ";
        is >> radius;
    }

    double area() const {
        return M_PI * radius * radius;
    }
};

class Square : virtual public Shape {
protected:
    double side;

public:
    Square(double s = 0.0) : Shape("Square"), side(s) {}
    Square(const std::string& n, double s) : Shape(n), side(s) {}
    virtual ~Square() {}

    virtual void print(std::ostream& os) const override {
        Shape::print(os);
        os << ", Side: " << side;
    }

    virtual void input(std::istream& is) override {
        Shape::input(is);
        std::cout << "Enter side length: ";
        is >> side;
    }

    double area() const {
        return side * side;
    }
};

class InscribedCircle : public Circle, public Square {
public:
    InscribedCircle(double s = 0.0)
        : Shape("InscribedCircle"), Circle("Circle", s / 2.0), Square("Square", s) {}

    virtual ~InscribedCircle() {}

    virtual void print(std::ostream& os) const override {
        Shape::print(os);
        os << "\nFrom Square - Side: " << Square::side
            << ", Area: " << Square::area()
            << "\nFrom Circle - Radius: " << Circle::radius
            << ", Area: " << Circle::area();
    }

    virtual void input(std::istream& is) override {
        std::cout << "Enter side for square (circle will be inscribed): ";
        is >> Square::side;
        Circle::radius = Square::side / 2.0;
    }
};