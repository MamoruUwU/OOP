#include <iostream>
#include "Person.h"
#include "tasks5.h"


void task5_3()
{
    Teacher t1;
    std::cout << "Fill in teacher information:\n";
    std::cin >> t1;

    std::cout << "\nTeacher details:\n";
    std::cout << t1 << std::endl;

    std::cout << "\nTesting copy constructor:\n";
    Teacher t2 = t1;
    std::cout << t2 << std::endl;

    std::cout << "\nTesting assignment operator:\n";
    Teacher t3;
    t3 = t1;
    std::cout << t3 << std::endl;
    std::cin.get();
    system("cls");
}