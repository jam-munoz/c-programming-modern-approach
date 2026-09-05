/*Write a program that finds the roots of the equation ax2 + bx + c = 0 using the formula
Have the program prompt for the values of a, b, and c, then print both values of x. (If b2 –
4ac is negative, the program should instead print a message to the effect that the roots are
complex.)*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double a, b, c, res1, res2;
	printf("Enter a, b and c (a b c): ");
	if (scanf(" %lf %lf %lf", &a, &b, &c) != 3)
	{
		printf("Error. Wrong input.\n");
		exit(EXIT_FAILURE);
	}
	if (a == 0)
	{
		printf("Error. Not a quadratic equation.\n");
		exit(EXIT_FAILURE);
	}
	res1 = b * b - (4 * a * c);
	if (res1 < 0)
	{
		printf("The roots are complex.\n");
		return 0;
	}
	res1 = sqrt(res1);
	res2 = (-b - res1) / (2 * a);
	res1 = (-b + res1) / (2 * a);
	printf("x1 = %.2lf\nx2 = %.2lf\n", res1, res2);
	return 0;
}
