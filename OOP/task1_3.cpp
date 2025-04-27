#include <iostream>
#include <vector>
#include "tasks1.h"
#include "Methods.h"

void task_3(std::vector<int>& array) {
    int size = array.size();
    for (int i = 0; i < size; i++) {
        if (array[i] >= 0) {
            array.push_back(array[i]);
            array.erase(array.begin() + i);
            i--;
            size--;
        }
    }
    std::cin.get();
    system("cls");
}