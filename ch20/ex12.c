/*The following function supposedly combines two bytes to form an unsigned short integer.
 Explain why the function doesn’t work and show how to fix it.
 unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
 {
    return high_byte << 8 + low_byte;
 } */
#include <limits.h>

unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
{
    unsigned short out = high_byte;

    out <<= sizeof(unsigned char) * CHAR_BIT;
    out |= low_byte;
    return out;
}
