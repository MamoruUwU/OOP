#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Labs.h"

namespace Useful {

     void ConsoleSize_Move(int width, int height, int posX, int posY) {
        HWND console = GetConsoleWindow();

        int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        int screenHeight = GetSystemMetrics(SM_CYSCREEN);

        if (posX == -1 || posY == -1) {
            posX = (screenWidth - width) / 2;
            posY = (screenHeight - height) / 2;
        }

        MoveWindow(console, posX, posY, width, height, TRUE);
    }

    void LockConsoleSize(bool lock) {
        HWND console = GetConsoleWindow();
        LONG style = GetWindowLong(console, GWL_STYLE);

        if (lock) {
            style &= ~WS_SIZEBOX;
            style &= ~WS_MAXIMIZEBOX;
        }
        else {
            style |= WS_SIZEBOX;
            style |= WS_MAXIMIZEBOX;
        }
        SetWindowLong(console, GWL_STYLE, style);
        SetWindowPos(console, nullptr, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
    } 

    bool ChekNum(std::string NumberChek)
    {
        std::string number = "-0123456789";
        int chek = 0;
        std::string emptyStr;

        if (NumberChek == emptyStr)
            return true;

        for (int i = 0; i < NumberChek.length(); i++)
        {
            chek = 0;
            for (int j = 0; j < 11; j++)
            {
                if (NumberChek[i] == number[j])
                {
                    chek = 1;
                    break;
                }

                else
                    chek = 0;
            }
            if (chek == 0)
                return true;
        }
        return false;
    }

    void consoleHandle() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsole, { 0, 0 });
    }

    void HideCursor()
    {
        CONSOLE_CURSOR_INFO cursorInfo;
        cursorInfo.dwSize = 100;
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    }

    void display(const std::vector<std::string>& lines, int highlight) {
        HideCursor();
        consoleHandle();
        for (size_t i = 0; i < lines.size(); i++) {
            std::string line = lines[i];
            int pos = line.find("[");
            if (pos != std::string::npos && i == highlight) {
                line[pos + 1] = '<';
            }
            std::cout << line << (line.find("Task") != std::string::npos ? "  <== (Task)" : "") << std::endl;

        }
    }
}