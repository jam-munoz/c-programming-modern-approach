/* Write a program that computes the volume of a sphere with a 10-meter radius, using the for-
mula v = 4/3πr³. Write the fraction 4/3 as 4.0f/3.0f. (Try writing it as 4/3. What hap-
pens?) Hint: C doesn’t have an exponentiation operator, so you’ll need to multiply r by itself
twice to compute r3.*/

#include <math.h>
#include <stdio.h>

int main(void)
{
	double v, r = 10;

	v = 4.0 / 3.0 * M_PI * r * r * r;
	printf("Volume: %gm³\n", v);
}
