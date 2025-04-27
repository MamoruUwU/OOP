#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <cstdint>

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

int calcParity_modern_decrypt(int value, int bitCount)
{
    int count = 0;
    for (int k = 0; k < bitCount; k++)
        if ((value >> k) & 1)
            count++;

    return count & 1;
}

int task_2_3_modern_decrypt() {
    std::fstream binFile("encrypted.bin", std::ios::in | std::ios::binary);
    if (!binFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }

    std::vector<DataUnion> encryptedData(ROWS * COLS);
    std::vector<char> decryptedText(ROWS * COLS);

    binFile.read(reinterpret_cast<char*>(encryptedData.data()), ROWS * COLS * sizeof(DataUnion));
    binFile.close();

    int index = 0;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            DataUnion d = encryptedData[index];

            if (d.fields.row != row || d.fields.col != col) {
                std::cerr << "Data corruption detected at position: " << row << ", " << col << std::endl;
                return 1;
            }

            if ((calcParity_modern_decrypt(d.fields.row, 4) + calcParity_modern_decrypt(d.fields.col, 4)) % 2 != d.fields.parity1 ||
                calcParity_modern_decrypt(d.fields.character, 8) != d.fields.parity2) {
                std::cerr << "Parity check failed at position: " << row << ", " << col << std::endl;
                return 1;
            }

            decryptedText[index] = d.fields.character;
            index++;
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << decryptedText[i * COLS + j];
        }
        std::cout << std::endl;
    }
    system("cls");
    return 0;
}