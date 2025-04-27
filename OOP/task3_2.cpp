#include <iostream>
#include <cmath>
#include "Vector.h"

int Vector::objectCount = 0;


void task3_2() {
    Vector v1;
    Vector v2(3.5);
    double arr[] = { 1.0, 2.0, 3.0 };
    Vector v3(arr);
    Vector v4(nullptr);

    v1.print();
    v2.print();
    v3.print();
    v4.print();

    Vector v5 = v2.add(v3);
    v5.print();

    Vector v6 = v3.subtract(v2);
    v6.print();

    Vector v7 = v3.crossProduct(v2);
    v7.print();

    v3.divide(2);
    v3.print();

    v3.divide(0);
    std::cout << "State after division by zero: " << v3.getState() << std::endl;

    std::cout << "Object count: " << Vector::getObjectCount() << std::endl;

    std::cin.ignore();
	std::cin.get();
    system("cls");
}
