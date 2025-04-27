#include <iostream>
#include <vector>
#include <string>
#include "tasks_1.h"

using namespace std;

void add_elements_random(vector<int>& array, int n) {
    for (int i = 0; i < n; i++) {
        array.push_back(rand() % (30) - 15);
    }
}

void add_elements(vector<int>& array, int n) {
    cout << "Enter element: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        array.push_back(x);
    }
}

void print_array(vector<int> array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void print_task_3(vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
        if (i % 10 == 9) cout << endl;
    }
    cout << endl;
}