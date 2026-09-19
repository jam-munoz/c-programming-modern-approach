/* (C99) Write a program that displays the nth roots of unity when given a positive integer n.
The nth roots of unity are given by the formula e^2πik/n, where k is an integer between 0 and n – 1.*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("Invalid value.\n");
		exit(EXIT_FAILURE);
	}
	for (int k = 0; k < n; k++)
	{
		double theta = 2.0 * M_PI * k / n;
		double real = cos(theta);
		double imag = sin(theta);

		printf("root %d: %g + %gi\n", k + 1, real, imag);
	}
}
