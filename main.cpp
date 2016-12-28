/*
** Bitwise addition
** Do not handle all edge cases (negative integers, overflows, endiandness)
*/

#include <iostream>
#include <cstdint>

static const int INTEGER_SIZE = 32;

int32_t bitwiseAddition(int32_t first, int32_t second)
{
    int32_t result = first;

    // We handle the general case using bit-level xor
    for (int i = 0; i < INTEGER_SIZE; ++i)
        result ^= ((second >> i) & 1) << i;

    // Then we handle the carry over
    for (int i = 0; i < INTEGER_SIZE - 1; ++i)
    {
        if (((first >> i) & 1) == 1 && ((second >> i) & 1) == 1)
            result |= 1 << (i + 1);
    }
    return result;
}

int main()
{
    std::cout << bitwiseAddition(3, 3) << std::endl;
    std::cout << bitwiseAddition(2, 5) << std::endl;
    std::cout << bitwiseAddition(12, 50) << std::endl;
    std::cout << bitwiseAddition(555, 555) << std::endl;
    std::cout << bitwiseAddition(123456789, 123456789) << std::endl;
}
