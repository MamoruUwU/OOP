#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace Useful
{
	bool ChekNum(std::string NumberChek);
	void display(const std::vector<std::string>& lines, int highlight);
	void ConsoleSize_Move(int width, int height, int posX, int posY);
	void LockConsoleSize(bool lock);
}
void lab1();
void lab2();
void lab3();
void lab4();
int visual();