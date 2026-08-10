#include <stdio.h>

int main ()
{
    int number[3];
    printf ("Enter a three-digit number: ");
    scanf ("%1d%1d%1d", &number[0], &number[1], &number[2]);
    printf ("The reversal is: %d%d%d\n", number[2], number[1], number[0]);
    return 0;
} 