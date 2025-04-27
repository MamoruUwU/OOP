#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "tasks4.h"
#include "Labs.h"

void lab4() {
    bool flag = true;
    do {
        int highlight = lab4_visual();
        switch (highlight - 6)
        {
        case 1:
        {
            system("cls");
            task4_1();
            break;
        }
        case 2:
        {
            system("cls");
            task4_2();
            std::cin.get();
            break;

        }

        case 3:
        {
            system("cls");
            task4_3();
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