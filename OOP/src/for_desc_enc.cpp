#include <iostream>
#include "calcParity.h"
#include <cstdint>

using namespace std;

int calcParity(int value, int bitCount)
{
    int count = 0;
    for (int k = 0; k < bitCount; k++)
        if ((value >> k) & 1)
            count++;

    return count & 1;
}