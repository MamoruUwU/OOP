#include <iostream>
#include <vector>
#include <string>
#include "tasks1.h"
#include "Methods.h"

namespace Methods {
    void add_elements_randoms(std::vector<int>& array, int n);
    void add_elements(std::vector<int>& array, int n);
    void print_array(std::vector<int> array);
    void print_task_3(std::vector<int>& array);
}

void Methods::add_elements_randoms(std::vector<int>& array, int n) {
    for (int i = 0; i < n; i++) {
        array.push_back(rand() % 30 - 15);
    }
}

void Methods::add_elements(std::vector<int>& array, int n) {
    std::cout << "Enter element: ";
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        array.push_back(x);
    }
}

void Methods::print_array(std::vector<int> array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void Methods::print_task_3(std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
        if (i % 10 == 9) std::cout << std::endl;
    }
    std::cout << std::endl;
}
