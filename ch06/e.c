/*The value of the mathematical constant e can be expressed as an infinite series:
e = 1 + 1/1! + 1/2! + 1/3! + …
Write a program that approximates e by computing the value of
1 + 1/1! + 1/2! + 1/3! + … + 1/n!
where n is an integer entered by the user.*/

#include <stdio.h>

int main(void)
{
    int i;
    float j, e = 1.0f;
    printf ("Enter an integer: ");
    scanf ("%d", &i);
    
    for (j = 1.0f; j <= i; j++)
        e = (e + (1.0f / (j * j)));

    printf ("Value of e: %f\n", e);
    return 0;
}