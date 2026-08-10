/*Write a program that asks the user to enter two integers, then calculates and displays their
greatest common divisor (GCD):
Enter two integers: 12 28
Greatest common divisor: 4
Hint: The classic algorithm for computing the GCD, known as Euclid’s algorithm, goes as
follows: Let m and n be variables containing the two numbers. If n is 0, then stop: m con-
tains the GCD. Otherwise, compute the remainder when m is divided by n. Copy n into m
and copy the remainder into n. Then repeat the process, starting with testing whether n is 0.*/

#include <stdio.h>

int main(void)
{
    int i, j, k;
    char *gcd = "Greatest common divisor: ";
    printf ("Enter two integers: ");
    scanf ("%d%d", &i, &j);

    while (j != 0)
    {
        k = i % j;
        i = j;
        j = k;
    }
    if (i == 0) 
    {
        printf ("%s%d\n", gcd, j);
    }
    else if (j == 0)
    {
        printf ("%s%d\n", gcd, i);
    }
    return 0;
}