#include "tasks_1.h"
#include "Group.h"

using namespace std;


void lab1()
{
    int n;
    vector<int> array_a;
    vector<int> array_b;
    vector<int> array_c;
    int t;
    srand(time(nullptr));

    string choiceStr;
    int choice;
    do {
        cout << "Task 1 - arrays" << endl;
        cout << "Task 2 - max in array" << endl;
        cout << "Task 3 - additional task" << endl;
        cout << "Close program (4)" << endl;
        do {
            cout << "Enter task number: ";
            cin >> choiceStr;
            choice = atoi(choiceStr.c_str());
        } while (choice < 1 || choice > 4);

        switch (choice) {
        case 1: {                         // Task1
            array_a.clear();
            array_b.clear();
            array_c.clear();

            cout << "Enter n: ";
            cin >> n;
            cout << "Would you like to add random elements or input yourself? (1 - random, 2 - yourself): ";
            cin >> choice;
            switch (choice)
            {
            case 1: {
                add_elements_random(array_a, n * 2);
                add_elements_random(array_b, n * 2);
                break;
            }
            case 2: {
                cout << "Array A: " << endl;
                add_elements(array_a, n * 2);
                cout << "Array B: " << endl;
                add_elements(array_b, n * 2);
                break;
            }
            }

            cout << "Array A: " << endl;
            print_array(array_a);

            cout << "Array B: " << endl;
            print_array(array_b);
            task_1(array_a, array_b, array_c);

            cout << "Array C: " << endl;
            print_array(array_c);
            break;
        }
        case 2: {                              // Task2
            array_a.clear();

            cout << "Enter n: ";
            cin >> n;
            cout << "Enter t: ";
            cin >> t;
            add_elements(array_a, n);
            print_array(array_a);
            task_2(array_a, t);
            break;
        }
        case 3: {                              // Task3
            array_a.clear();
            do {
                cout << "Enter n (<= 400): ";
                cin >> n;
            } while (n > 400);
            add_elements_random(array_a, n);
            print_task_3(array_a);

            task_3(array_a);
            print_task_3(array_a);
            break;
        }
        }
    } while (choice != 4);
}