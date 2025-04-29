#include <iostream>
#include "Wheels.h"
#include "tasks5.h"



void task5_2()
{
	Wheels wheels("winter tire", 20, 4);
	Car car("Honda Civic", 20, 4, 100);
	Bicycle bicycle("Ukrayina", 20, 2, 10);

	car.print();
	bicycle.print();
	wheels.print();

	std::cin.get();
	system("cls");
}