#include <iostream>
#include "Vector3D.h"
#include "tasks4.h"

void task4_1() {
    Vector3D v1;
    Vector3D v2(5);
    double arr[] = { 1, 2, 3 };
    Vector3D v3(arr);
    Vector3D v4(nullptr);

    v1 = v2 + v3;
    v1();
    std::cout << "Vector after ++: " << ++v1 << "\n";
    std::cout << "Check !v1: " << (!v1 ? "true" : "false") << "\n";
    std::cout << "Perpend: " << ~v1 << "\n";
    std::cout << "Negative: " << -v1 << "\n";

    v1[0] = 10; 
    std::cout << "Value x: " << v1[0] << "\n";

    std::cout << "Created objects: " << Vector3D::getObjectCount() << '\n';
    std::cin.get();
    system("cls");
}
