#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <cstdint>
#include "tasks2.h"
#include "calcParity.h"

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

int task_2_3_modern_decrypt() {
    fstream binFile("encrypted.bin", ios::in | ios::binary);
    if (!binFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    vector<DataUnion> encryptedData(ROWS * COLS);
    vector<char> decryptedText(ROWS * COLS);

    binFile.read(reinterpret_cast<char*>(encryptedData.data()), ROWS * COLS * sizeof(DataUnion));
    binFile.close();

    int index = 0;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            DataUnion d = encryptedData[index];

            if (d.fields.row != row || d.fields.col != col) {
                cerr << "Data corruption detected at position: " << row << ", " << col << endl;
                return 1;
            }

            if ((calcParity(d.fields.row, 4) + calcParity(d.fields.col, 4)) % 2 != d.fields.parity1 ||
                calcParity(d.fields.character, 8) != d.fields.parity2) {
                cerr << "Parity check failed at position: " << row << ", " << col << endl;
                return 1;
            }

            decryptedText[index] = d.fields.character;
            index++;
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << decryptedText[i * COLS + j];
        }
        cout << endl;
    }

    return 0;
}
