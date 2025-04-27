#include "Group.h"
#include <fstream>
using namespace Useful;
using namespace std;

int visual() {
    /* ConsoleSize_Move(500, 500);
    LockConsoleSize(true); */
    vector<string> lines;
    string line;
    fstream file("Visual.txt", ios::out);
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }
    cin.get();
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