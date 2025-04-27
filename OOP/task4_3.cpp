#include "MatrixLong.h"
#include "tasks4.h"
#include <iostream>

void task4_3() {
    MatrixLong A(3, 3, 2);
    MatrixLong B(3, 3, 3);
    MatrixLong C = A + B;
    MatrixLong D = C * 2;
    MatrixLong E = D * B;
    MatrixLong F = -E;

    std::cout << "Matrix A:\n" << A;
    std::cout << "Matrix B:\n" << B;
    std::cout << "Matrix C = A + B:\n" << C;
    std::cout << "Matrix D = C * 2:\n" << D;
    std::cout << "Matrix E = D * B:\n" << E;
    std::cout << "Matrix F = -E:\n" << F;

    std::cout << "Total matrix objects: " << MatrixLong::getMatrixCount() << std::endl;

    std::cin.ignore();
    std::cin.get();
    std::cin.get();
    system("cls");
}
