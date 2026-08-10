#include <stdio.h>

int main ()
{
    int number;
    printf ("Enter a three-digit number: ");
    scanf ("%d", &number);
    if (number < 100 || number > 999)
        {
            return 1;
        }
    int reversal = (((number % 100) % 10) * 100) + (((number % 100) / 10) * 10) + (number / 100);
    printf ("The reversal is: %d\n", reversal);
    return 0;
} 