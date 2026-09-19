/* Write a program that converts a complex number in Cartesian coordinates to polar
form. The user will enter a and b (the real and imaginary parts of the number); the program
will display the values of r and θ.*/

#include <math.h>
#include <stdio.h>

int main(void)
{
	double a, b;
	printf("Enter the real part of a complex number: ");
	scanf("%lf", &a);
	printf("Enter the imaginary part of a complex number: ");
	scanf("%lf", &b);

	double r = sqrt(a * a + b * b);
	double theta = atan2(b, a);
	printf("r = %g\n", r);
    printf("theta = %g*pi\n", theta / M_PI);
}
