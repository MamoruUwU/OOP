#include <iostream>
#include <fstream>
#include "Group.h"
#include "tasks2.h"

using namespace Useful;
using namespace std;


int lab2_visual() {
    /* ConsoleSize_Move(500, 500);
    LockConsoleSize(true); */

    vector<string> lines;
    string line;
    fstream file("Visual_Lab2.txt", ios::in);
    while (getline(file, line)) lines.push_back(line);
    file.close();

    int highlight = findLab1Index(lines);
    int minHighlight = highlight;

    char input;
    display(lines, highlight);

    while ((input = cin.get()) != 13) {
        if (input == 72 && highlight > minHighlight) highlight--;
        if (input == 80 && highlight < lines.size() - 1) highlight++;
        display(lines, highlight);
    }
    return highlight;
}