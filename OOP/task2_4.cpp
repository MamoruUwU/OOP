#include <iostream>
#include <string>
#include <vector>


std::string dec_to_bin(int Number) {
    if (Number == 0) return "0";
    std::string BinaryNum;
    while (Number > 0) {
        BinaryNum = std::to_string(Number % 2) + BinaryNum;
        Number /= 2;
    }
    return BinaryNum;
}

int bin_to_dec(const std::string& str) {
    int result = 0;
    for (char c : str) {
        result = result * 2 + (c - '0');
    }
    return result;
}

std::vector<int> power_two(const std::string& str) {
    std::vector<int> result;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '1') {
            result.push_back(str.length() - 1 - i);
        }
    }
    return result;
}

void task_2_4() {
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    std::string binary_b = dec_to_bin(b);
    std::cout << "Binary of b: " << binary_b << std::endl;

    std::vector<int> powers = power_two(binary_b);

    int res = 0;
    for (int p : powers) {
        res += (a << p);
    }

    std::cout << "Multiplication: " << a * b << std::endl;
    std::cout << "Binary multiplication result: " << res << std::endl;

    std::cin.ignore();
    std::cin.get();
    system("cls");
}
