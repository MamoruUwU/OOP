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

int task_2_2_decrypt() {
    fstream binFile("encrypted.bin", ios::in | ios::binary);

    if (!binFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    vector<uint16_t> encryptedData;
    vector<char> decryptedText(ROWS * COLS);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            uint16_t value;
            binFile.read(reinterpret_cast<char*>(&value), sizeof(uint16_t));
            encryptedData.push_back(value);
        }
    }

    binFile.close();

    int index = 0;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            uint16_t encoded = encryptedData[index];

            int secondParity = encoded & 1;
            encoded >>= 1;
            int firstParity = encoded & 1;
            encoded >>= 1;
            char ch = encoded & 0xFF;
            encoded >>= 8;
            int decodedCol = encoded & 0xF;
            encoded >>= 4;
            int decodedRow = encoded & 0x3;

            if (decodedRow != row || decodedCol != col) {
                cerr << "Data corruption detected at position: " << row << ", " << col << endl;
                return 1;
            }

            if ((calcParity(decodedRow, 4) + calcParity(decodedCol, 4)) % 2 != firstParity ||
                calcParity(ch, 8) != secondParity) {
                cerr << "Parity check failed at position: " << row << ", " << col << endl;
                return 1;
            }

            decryptedText[index] = ch;
            index++;
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            char c = decryptedText[i * COLS + j];
            if (isprint(c)) {
                cout << c;
            }
            else {
                cout << '.';
            }
        }
        cout << endl;
    }


    return 0;
}
