#include <iostream>
#include <stdexcept>
#include "Matrix.h"

int Matrix::object_count = 0;

void task3_3() {
    Matrix m1;
    Matrix m2(3);
    Matrix m3(3, 4, 7);

    std::cout << "Matrix 1:\n";
    m1.print();

    std::cout << "Matrix 2:\n";
    m2.print();

    std::cout << "Matrix 3:\n";
    m3.print();

    std::cin.get();
    system("cls");
}
