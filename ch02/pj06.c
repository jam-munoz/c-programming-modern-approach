/* Modify the program of Programming Project 5 so that the polynomial is evaluated using the
following formula:
((((3x + 2)x – 5)x – 1)x + 7)x – 6
Note that the modified program performs fewer multiplications. This technique for evaluat-
ing polynomials is known as Horner’s Rule.*/

#include <stdio.h>

int main(void)
{
	long x;
	long result;
	printf("Enter a value for x: ");
	scanf("%ld", &x);
	result = ((((3*x + 2)*x - 5)*x - 1)*x + 7)*x - 6;
	printf("Result: %ld\n", result);
}
