/* (C99) Write a program that converts a complex number in polar coordinates to Cartesian
form. After the user enters the values of r and θ, the program will display the number in the
form a + bi, where
a = r cos θ
b = r sin θ*/

#include <math.h>
#include <stdio.h>

int main(void)
{
	double r, theta;
	printf("Enter the value of r: ");
	scanf("%lf", &r);
	printf("Enter the value of theta: ");
	scanf("%lf", &theta);

	double a = r * cos(theta);
	double b = r * sin(theta);
	if (b >= 0)
		printf("In binomial form: %g + %gi\n", a, b);
	else
		printf("In binomial form: %g - %gi\n", a, fabs(b));
}
