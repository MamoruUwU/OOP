#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <cstdint>
#include "calcParity.h"
#include "tasks2.h"

using namespace std;

const int ROWS = 4;
const int COLS = 16;

struct EncodedData {
    uint16_t parity2 : 1;
    uint16_t parity1 : 1;
    uint16_t character : 8;
    uint16_t col : 4;
    uint16_t row : 2;
};

union DataUnion {
    EncodedData fields;
    uint16_t encoded;
};

int task_2_3_modern_encrypt() {
    vector<DataUnion> data;
    vector<string> lines;

    fstream binFile("encrypted.bin", ios::out | ios::binary);
    if (!binFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        string line;
        cout << "Enter row #" << i + 1 << ": ";
        getline(cin, line);

        if (line.length() < COLS)
            line += string(COLS - line.length(), ' ');
        lines.push_back(line);
    }

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            DataUnion d;
            d.fields.row = row & 3;
            d.fields.col = col & 15;
            d.fields.character = lines[row][col];
            d.fields.parity1 = (calcParity(row, 4) + calcParity(col, 4)) & 1;
            d.fields.parity2 = calcParity(d.fields.character, 8);
            data.push_back(d);

            cout << bitset<16>(d.encoded) << " " << lines[row][col] << endl;
        }
    }

    binFile.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(DataUnion));
    binFile.close();
}
