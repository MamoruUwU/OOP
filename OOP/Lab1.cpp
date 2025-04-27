#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Methods.h"
#include "tasks1.h"
#include "Labs.h"

void lab1() {
    int n;
    std::vector<int> array_a;
    std::vector<int> array_b;
    std::vector<int> array_c;
    int t;
    srand(time(nullptr));

    bool flag = true;
    do {
        int highlight = lab1_visual();
        switch (highlight - 6)
        {
        case 1:
        {
            system("cls");
            array_a.clear();
            array_b.clear();
            array_c.clear();

            std::cout << "Enter n: ";
            std::cin >> n;

            char choice;
            std::cout << "Would you like to add random elements or input yourself? (1 - random, 2 - yourself): ";
            std::cin >> choice;
            switch (choice)
            {
            case 1: {
                Methods::add_elements_randoms(array_a, n * 2);
                Methods::add_elements_randoms(array_b, n * 2);
                break;
            }
            case 2: {
                std::cout << "Array A: " << std::endl;
                Methods::add_elements(array_a, n * 2);
                std::cout << "Array B: " << std::endl;
                Methods::add_elements(array_b, n * 2);
                break;
            }
            }

            std::cout << "Array A: " << std::endl;
            Methods::print_array(array_a);

            std::cout << "Array B: " << std::endl;
            Methods::print_array(array_b);
            task_1(array_a, array_b, array_c);

            std::cout << "Array C: " << std::endl;
            Methods::print_array(array_c);
            break;
        }
        case 2:
        {
            system("cls");
            array_a.clear();

            std::cout << "Enter n: ";
            std::cin >> n;
            std::cout << "Enter t: ";
            std::cin >> t;
            Methods::add_elements(array_a, n);
            Methods::print_array(array_a);
            task_2(array_a, t);
            break;

        }

        case 3:
        {
            system("cls");
            array_a.clear();
            do {
                std::cout << "Enter n (<= 400): ";
                std::cin >> n;
            } while (n > 400);
            Methods::add_elements_randoms(array_a, n);
            Methods::print_task_3(array_a);

            task_3(array_a);
            Methods::print_task_3(array_a);
            break;
        }

        case 4:
        {
            system("cls");
            flag = false;
            break;
        }
        }
        
    } while (flag == true);
}