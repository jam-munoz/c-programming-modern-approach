/* Modify the program of Programming Project 2 so that it prompts the user to enter the radius
of the sphere.*/

#include <math.h>
#include <stdio.h>

int main(void)
{
	double v, r;
	printf("Enter the radius of the sphere: ");
	scanf("%lf", &r);

	v = 4.0 / 3.0 * M_PI * r * r * r;
	printf("Volume: %gm³\n", v);
}
