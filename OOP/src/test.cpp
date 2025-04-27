#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int findLab1Index(const vector<string>& lines) {
    for (size_t i = 0; i < lines.size(); i++) {
        if (lines[i].find("Lab1") != string::npos) {
            return i;
        }
    }
    return 0;
}

void display(const vector<string>& lines, int highlight) {
    system("clear");
    for (size_t i = 0; i < lines.size(); i++) {
        string line = lines[i];
        int pos = line.find("[");
        if (pos != string::npos && i == highlight) {
            line[pos + 1] = '<';
        }
        cout << line << (line.find("lab") != string::npos ? "  <== (lab)" : "") << endl;
    }
}

int main() {
    system("clear");
    vector<string> lines;
    string line;
    fstream file("src/Visual.txt", ios::in); // Use ios::in to open for reading
    if (!file.is_open()) {
        cout << "Failed to open the file!" << endl;
        return 1;
    }

    cout << "File opened" << endl;
    while (getline(file, line)) { // This will automatically check for EOF
        cout << line << endl;
        lines.push_back(line);
    }

    file.close();
    cout << "File closed" << endl;
    cin.get();

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
}