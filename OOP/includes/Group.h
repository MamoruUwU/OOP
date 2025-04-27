#pragma once
#include <iostream>
#include <vector>
#include <string>


void lab1();
int visual();

namespace Useful {
	bool ChekNum(std::string NumberChek);
	int findLab1Index(const std::vector<std::string>& lines);
	void display(const std::vector<std::string>& lines, int highlight);
};
