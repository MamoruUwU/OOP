#include <iostream>
#include <vector>
#include <climits>
#include "tasks_1.h"

using namespace std;

void task_1(vector<int>& array_a, vector<int>& array_b, vector<int>& array_c) {
    for (int i = 0; i < (array_a.size() / 2); i++) array_c.push_back(array_a[i] + array_b[i]);
    for (int j = array_b.size() / 2; j < array_b.size(); j++) array_c.push_back(array_a[j] - array_b[j]);

}