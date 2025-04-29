#include <iostream>
#include "Liquid.h"
#include "tasks5.h"



void task5_1()
{
	Liquid water("Water", 1000);
	Alcohol whiskey("whiskey", 800, 40);
	whiskey.print();
	whiskey.new_data("whiskey", 900);
	water.print();
	whiskey.print();

	std::cin.get();
	system("cls");
}