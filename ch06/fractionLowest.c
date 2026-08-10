/*Write a program that asks the user to enter a fraction, then reduces the fraction to lowest terms:
Enter a fraction: 6/12
In lowest terms: 1/2
Hint: To reduce a fraction to lowest terms, first compute the GCD of the numerator and
denominator. Then divide both the numerator and denominator by the GCD.*/

#include <stdio.h>

int main(void)
{
    int i, j, k, a, b;
    printf ("Enter a fraction: ");
    scanf ("%d/%d", &i, &j);
    a = i;
    b = j;

    // calculate gcd
    while (j != 0)
    {
        k = i % j;
        i = j;
        j = k;
    }
    if (j == 0) 
    {
        printf ("In lowest terms: %d/%d\n", (a / i), (b / i));
    }
    return 0;
}