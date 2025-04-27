#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "tasks1.h"
#include "Labs.h"

int lab1_visual() {
    Useful::ConsoleSize_Move(500, 500, -1, -1);
    Useful::LockConsoleSize(true);

    std::vector<std::string> lines;
    std::string line;
    std::fstream file("Lab1_visual.txt", std::ios::in);
    while (std::getline(file, line)) lines.push_back(line);
    file.close();

    int highlight = 0;
    for (int i = 0; i < lines.size(); ++i) {
        if (lines[i].find("[") != std::string::npos) {
            highlight = i;
            break;
        }
    }
    int minHighlight = highlight;

    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_PROCESSED_INPUT);

    Useful::display(lines, highlight);

    INPUT_RECORD inputRecord;
    DWORD events;

    while (true) {
        ReadConsoleInput(hStdin, &inputRecord, 1, &events);

        if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {
            switch (inputRecord.Event.KeyEvent.wVirtualKeyCode) {
            case VK_UP:
                if (highlight > minHighlight) highlight--;
                else highlight = lines.size() - 1;
                break;
            case VK_DOWN:
                if (highlight < lines.size() - 1) highlight++;
                else highlight = 7;
                break;
            case VK_RETURN:
                return highlight;
            }

            Useful::display(lines, highlight);
        }
    }
}