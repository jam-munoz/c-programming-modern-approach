/* Modify Programming Project 3 from Chapter 6 so that it includes the following function:
void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);
numerator and denominator are the numerator and denominator of a fraction.
reduced_numerator and reduced_denominator are pointers to variables in
which the function will store the numerator and denominator of the fraction once it has been
reduced to lowest terms.*/

#include <stdio.h>
void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void)
{
    int i, j, k, l;
    printf ("Enter a fraction: ");
    scanf ("%d/%d", &i, &j);
    reduce(i, j, &k, &l);
    printf ("In lowest terms: %d/%d\n", k, l);
    return 0;
}
void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int temp, gcd = numerator, den = denominator;
    while (den != 0)
    {
        temp = gcd % den;
        gcd = den;
        den = temp;
    }
    *reduced_numerator = (numerator / gcd);
    *reduced_denominator = (denominator / gcd);
}