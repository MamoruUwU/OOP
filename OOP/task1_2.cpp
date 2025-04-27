#include <iostream>
#include <vector>
#include <climits>
#include "tasks1.h"
#include "Methods.h"

void task_2(std::vector<int>& array, int t) {
    int pos = -1;
    int max = INT_MIN;
    int last_t_index = -1;

    for (int i = array.size() - 1; i >= 0; i--) {
        if (array[i] == t) {
            last_t_index = i;
            break;
        }
    }

    for (int i = last_t_index; i < array.size(); i++) {
        if (array[i] < 0 && array[i] > max) {
            max = array[i];
            pos = i;
        }
    }

    if (pos != -1)
        std::cout << "Max index: " << pos << std::endl;
    else
        std::cout << "Max not found :(";
    std::cin.ignore();
    std::cin.get();
    system("cls");
}