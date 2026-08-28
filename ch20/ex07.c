/* Write the following functions:
unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);
rotate_left should return the result of shifting the bits in i to the left by n places,
with the bits that were “shifted off” moved to the right end of i. (For example, the call
rotate_left(0x12345678, 4) should return 0x23456781 if integers are 32 bits
long.) rotate_right is similar, but it should “rotate” bits to the right instead of the left.*/
#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n)
{
    n = n % 32;
    if (n == 0)
        return (i);

    unsigned int left = i << n;
    unsigned int right = i >> (32 - n);
    return left | right;
}

unsigned int rotate_right(unsigned int i, int n)
{
    n = n % 32;
    if (n == 0)
        return (i);

    unsigned int left = i >> n;
    unsigned int right = i << (32 - n);
    return left | right;
}

int main(void)
{
    unsigned int nb;
    nb = rotate_left(0x12345678, 4);
    printf("Number with bytes swapped: %x\n", nb);
}
