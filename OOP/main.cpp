#include <iostream>
#include "Labs.h"

int main() {
    bool flag = true;
    do {
        int highlight = visual();
        std::cout << highlight << std::endl;
        switch (highlight - 6)
        {
        case 1:
        {
            system("cls");
            lab1();
            break;
        }
        case 2:
        {
            system("cls");
            lab2();
            break;
        }
        case 3:
        {
            system("cls");
            lab3();
            break;
        }

        case 4:
        {
            system("cls");
            lab4();
            break;
        }

        case 5:
        {
            system("cls");
            lab5();
            break;
        }

        case 6:
        {
            system("cls");
            lab6();
            break;
        }

        case 7:
        {
            system("cls");
            std::cout << "Coming soon..." << std::endl;
            std::cin.get();
            break;
        }

        case 8:
        {
            system("cls");
            flag = false;
			break;
        }
        }
    } while (flag == true);

}