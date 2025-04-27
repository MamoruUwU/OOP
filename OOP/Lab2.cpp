#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "tasks2.h"
#include "Labs.h"

void lab2() {
    bool flag = true;
    do {
        int highlight = lab2_visual();
        switch (highlight - 6)
        {
        case 1:
        {
            system("cls");
            task_2_1();
            break;
        }
        case 2:
        {
            system("cls");
            task_2_2_encrypt();
            std::cin.get();
            break;

        }

        case 3:
        {
            system("cls");
            task_2_2_decrypt();
            std::cin.get();
            break;
        }

        case 4:
        {
            system("cls");
            task_2_3_modern_encrypt();
            std::cin.get();
            break;
        }

        case 5:
        {
            system("cls");
            task_2_3_modern_decrypt();
            std::cin.get();
            break;
        }
        case 6:
        {
			system("cls");
			task_2_4();
			break;
        }
        case 7:
        {
            system("cls");
			flag = false;
            break;
        }
        }
    } while (flag == true);
}