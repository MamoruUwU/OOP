#include <iostream>
#include "Group.h"

using namespace std;

int run() {
    do {        
        int highlight = visual();
        cout << highlight << endl;
        switch (highlight - 9)
        {
        case 1:
        { 
            system("clear");
            lab1();
            break;
        }
        case 2:
        {
            system("clear");


            std::cin.get();
            break;

        }

        case 3:
        {
            system("clear");
            std::cout << "Coming soon..." << endl;
            std::cin.get();
            break;
        }

        case 4:
        {
            system("clear");
            std::cout << "Coming soon..." << endl;
            std::cin.get();
            break;
        }

        case 5:
        {
            system("clear");
            cout << "Coming soon..." << endl;
            std::cin.get();
            break;
        }

        case 6:
        {
            system("clear");
            std::cout << "Coming soon..." << endl;
            std::cin.get();
            break;
        }

        case 7:
        {
            system("clear");
            std::cout << "Coming soon..." << endl;
            std::cin.get();
            break;
        }

        case 8:
        {
            system("clear");
            exit(0);
        }
        }
    } while (true);

}