#include <iostream>
#include <vector>
#include <climits>
#include "tasks1.h"
#include "Methods.h"

void task_1(std::vector<int>& array_a, std::vector<int>& array_b, std::vector<int>& array_c) {
    for (int i = 0; i < (array_a.size() / 2); i++) array_c.push_back(array_a[i] + array_b[i]);
    for (int j = array_b.size() / 2; j < array_b.size(); j++) array_c.push_back(array_a[j] - array_b[j]);

    std::cin.get();
    std::cin.get();
    system("cls");
}