#include <iostream>
#include <string>
#include <vector>
#include "tasks2.h"

using namespace std;


string dec_to_bin(int Number) {
    if (Number == 0) return "0";
    string BinaryNum;
    while (Number > 0) {
        BinaryNum = to_string(Number % 2) + BinaryNum;
        Number /= 2;
    }
    return BinaryNum;
}

int bin_to_dec(const string& str) {
    int result = 0;
    for (char c : str) {
        result = result * 2 + (c - '0');
    }
    return result;
}

vector<int> power_two(const string& str) {
    vector<int> result;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '1') {
            result.push_back(str.length() - 1 - i);
        }
    }
    return result;
}

void task_2_4() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    string binary_b = dec_to_bin(b);
    cout << "Binary of b: " << binary_b << endl;

    vector<int> powers = power_two(binary_b);

    int res = 0;
    for (int p : powers) {
        res += (a << p);
    }

    cout << "Multiplication: " << a * b << endl;
    cout << "Binary multiplication result: " << res << endl;
}
