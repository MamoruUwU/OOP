#include <iostream> 
#include "Employee.h"
#include "tasks6.h"

void task6_2()
{
    HourlyEmployee h("Andriy", 160, 120);
    SalariedEmployee s("Oksana", 25000);
    CommissionEmployee c("Ihor", 100000, 0.05);

    Employee* employees[] = { &h, &s, &c };

    for (Employee* emp : employees) {
        emp->print();
        std::cout << "-------------------\n";
    }

    std::cin.get();
    system("cls");
}