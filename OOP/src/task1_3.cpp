#include <iostream>
#include <vector>
#include "tasks_1.h"

using namespace std;

void task_3(vector<int>& array) {
    int size = array.size();
    for (int i = 0; i < size; i++) {
        if (array[i] >= 0) {
            array.push_back(array[i]);
            array.erase(array.begin() + i);
            i--;
            size--;
        }
    }
}