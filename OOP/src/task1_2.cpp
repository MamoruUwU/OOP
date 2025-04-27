#include <iostream>
#include <vector>
#include <climits>
#include "tasks_1.h"

using namespace std;

void task_2(vector<int>& array, int t) {
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
        cout << "Max index: " << pos << endl;
    else
        cout << "Max not found :(" << endl;
}