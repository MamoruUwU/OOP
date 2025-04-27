#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <cstdint>

const int ROWS = 4;
const int COLS = 16;

int calcParity_enscrypt(int value, int bitCount)
{
    int count = 0;
    for (int k = 0; k < bitCount; k++)
        if ((value >> k) & 1)
            count++;

    return count & 1;
}

int task_2_2_encrypt() {
    std::vector<uint16_t> data;
    std::vector<std::string> lines;

    std::fstream binFile("encrypted.bin", std::ios::out | std::ios::binary);

    if (!binFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        std::string line;
        std::cout << "Enter row #" << i + 1 << ": ";
        getline(std::cin, line);

        if (line.length() != COLS)
            line += std::string(COLS - line.length(), ' ');
        lines.push_back(line);
    }

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            char ch = lines[row][col];
            uint16_t encoded = (row & 3);
            encoded = (encoded << 4) | (col & 15);
            encoded = (encoded << 8) | ch;
            int firstParity = (calcParity_enscrypt(row, 4) + calcParity_enscrypt(col, 4)) & 1;
            int secondParity = calcParity_enscrypt(ch, 8);
            encoded = (encoded << 1) | firstParity;
            encoded = (encoded << 1) | secondParity;
            data.push_back(encoded);

            std::cout << std::bitset<16>(encoded) << " " << ch << std::endl;
        }
    }

    binFile.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(uint16_t));
    binFile.close();
    system("cls");
    return 0;
}
