#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <cstdint>
#include "tasks2.h"
#include "calcParity.h"


using namespace std;

const int ROWS = 4;
const int COLS = 16;

int task_2_2_encrypt() {
    vector<uint16_t> data;
    vector<string> lines;

    fstream binFile("encrypted.bin", ios::out | ios::binary);

    if (!binFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        string line;
        cout << "Enter row #" << i + 1 << ": ";
        getline(cin, line);

        if (line.length() != COLS)
            line += string(COLS - line.length(), ' ');
        lines.push_back(line);
    }

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            char ch = lines[row][col];
            uint16_t encoded = (row & 3);
            encoded = (encoded << 4) | (col & 15);
            encoded = (encoded << 8) | ch;
            int firstParity = (calcParity(row, 4) + calcParity(col, 4)) & 1;
            int secondParity = calcParity(ch, 8);
            encoded = (encoded << 1) | firstParity;
            encoded = (encoded << 1) | secondParity;
            data.push_back(encoded);

            cout << bitset<16>(encoded) << " " << ch << endl;
        }
    }

    binFile.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(uint16_t));
    binFile.close();
}
