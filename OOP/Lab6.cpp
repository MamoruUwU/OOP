#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "tasks6.h"
#include "Labs.h"

void lab6() {
    bool flag = true;
    do {
        int highlight = lab6_visual();
        switch (highlight - 6)
        {
        case 1:
        {
            system("cls");
            task6_1();
            break;
        }
        case 2:
        {
            system("cls");
            task6_2();
            std::cin.get();
            break;

        }

        case 3:
        {
            system("cls");
            task6_3();
            std::cin.get();
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