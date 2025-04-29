#include <iostream>
#include "Histogram.h"
#include "tasks6.h"


void task6_1()
{
    H obj_non_virtual;
    VH obj_virtual;

    std::cout << "Size without virtual inheritance: " << sizeof(obj_non_virtual) << " bytes\n";
    std::cout << "Size with virtual inheritance:    " << sizeof(obj_virtual) << " bytes\n";

    std::cin.get();
    system("cls");
}