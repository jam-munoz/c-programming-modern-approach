/*Write a program that prints the values of sizeof(int), sizeof(short),
sizeof(long), sizeof(float), sizeof(double) and sizeof(long double).*/ 

#include <stdio.h>

int main(void)
{
    int a = sizeof(int);
    int b = sizeof(short);
    int c = sizeof(long);
    int d = sizeof(float);
    int e = sizeof(double);
    int f = sizeof(long double);
    printf ("sizeof(int)=%d\nsizeof(short)=%d\nsizeof(long)=%d\nsizeof(float)=%d\nsizeof(double)=%d\nsizeof(long double)=%d\n", a, b, c, d, e, f);
    return 0;
}