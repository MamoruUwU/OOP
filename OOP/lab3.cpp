#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "tasks3.h"
#include "Labs.h"

void lab3() {
    bool flag = true;
    do {
        int highlight = lab3_visual();
        switch (highlight - 6)
        {
        case 1:
        {
            system("cls");
            task3_1();
            break;
        }
        case 2:
        {
            system("cls");
            task3_2();
            std::cin.get();
            break;

        }

        case 3:
        {
            system("cls");
            task3_3();
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