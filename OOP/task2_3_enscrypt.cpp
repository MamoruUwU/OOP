#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

int calcParity_modern_encrypt(int value, int bitCount)
{
    int count = 0;
    for (int k = 0; k < bitCount; k++)
        if ((value >> k) & 1)
            count++;

    return count & 1;
}

int task_2_3_modern_encrypt() {
    std::vector<DataUnion> data;
    std::vector<std::string> lines;

    std::fstream binFile("encrypted.bin", std::ios::out | std::ios::binary);
    if (!binFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        std::string line;
        std::cout << "Enter row #" << i + 1 << ": ";
        getline(std::cin, line);

        if (line.length() < COLS)
            line += std::string(COLS - line.length(), ' ');
        lines.push_back(line);
    }

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            DataUnion d;
            d.fields.row = row & 3;
            d.fields.col = col & 15;
            d.fields.character = lines[row][col];
            d.fields.parity1 = (calcParity_modern_encrypt(row, 4) + calcParity_modern_encrypt(col, 4)) & 1;
            d.fields.parity2 = calcParity_modern_encrypt(d.fields.character, 8);
            data.push_back(d);

            std::cout << std::bitset<16>(d.encoded) << " " << lines[row][col] << std::endl;
        }
    }

    binFile.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(DataUnion));
    binFile.close();
    system("cls");
    return 0;
    
}
