#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <cstdint>

const int ROWS = 4;
const int COLS = 16;

int calcParity_decrypt(int value, int bitCount)
{
    int count = 0;
    for (int k = 0; k < bitCount; k++)
        if ((value >> k) & 1)
            count++;

    return count & 1;
}

int task_2_2_decrypt() {
    std::fstream binFile("encrypted.bin", std::ios::in | std::ios::binary);

    if (!binFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }

    std::vector<uint16_t> encryptedData;
    std::vector<char> decryptedText(ROWS * COLS);

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
                std::cerr << "Data corruption detected at position: " << row << ", " << col << std::endl;
                return 1;
            }

            if ((calcParity_decrypt(decodedRow, 4) + calcParity_decrypt(decodedCol, 4)) % 2 != firstParity ||
                calcParity_decrypt(ch, 8) != secondParity) {
                std::cerr << "Parity check failed at position: " << row << ", " << col << std::endl;
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
                std::cout << c;
            }
            else {
                std::cout << '.';
            }
        }
        std::cout << std::endl;
    }
    system("cls");
    return 0;
}
