/*Write the following function:
unsigned int reverse_bits(unsigned int n);
reverse_bits should return an unsigned integer whose bits are the same as those in n
but in reverse order.*/
#include <limits.h>

unsigned int reverse_bits(unsigned int n)
{
    unsigned int sum = 0;
    const int bits = sizeof(unsigned int) * CHAR_BIT;

    for (int i = 0; i < bits; i++)
    {
        sum <<= 1;
        sum |= n & 1;
        n >>= 1;
    }
    return sum;
}
