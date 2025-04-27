#include <iostream>
#include <string>
#include "tasks4.h"
#include "FullName.h"

void task4_2() {
    StudentGroup group;
    std::cin >> group;

    std::cout << "All students:\n" << group;
    std::cin.get();



    int query = 3;
    FullName student = group[query];

    if (group.getError() == CodeError::NOT_FOUND)
        std::cout << "Student with index " << query << " not found.";
    else
        std::cout << "Student at index " << query << ": " << student;
    system("cls");
}
