#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "tasks5.h"
#include "Labs.h"

void lab5() {
    bool flag = true;
    do {
        int highlight = lab5_visual();
        switch (highlight - 6)
        {
        case 1:
        {
            system("cls");
            task5_1();
            break;
        }
        case 2:
        {
            system("cls");
            task5_2();
            std::cin.get();
            break;

        }

        case 3:
        {
            system("cls");
            task5_3();
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