/*(C99) Make the following modifications to the quadratic.c program of Section 27.4:
(a) Have the user enter the coefficients of the polynomial (the values of the variables a, b, and c).
(b) Have the program test the discriminant before displaying the values of the roots. If the
discriminant is negative, have the program display the roots in the same way as before. If it’s
nonnegative, have the program display the roots as real numbers (without an imaginary part).
For example, if the quadratic equation is x2 + x – 2 = 0, the output of the program would be
root1 = 1
root2 = -2
(c) Modify the program so that it displays a complex number with a negative imaginary
part as a – bi instead of a + –bi. For example, the output of the program with the original
coefficients would be
root1 = -0.2 + 0.4i
root2 = -0.2 - 0.4i*/

/* quadratic.c (Chapter 27, page 723) */
/* Finds the roots of the equation 5x² + 2x + 1 = 0 */

#include <complex.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
	double a, b, c, discriminant;
	printf("Enter the value of variable a: ");
	scanf("%lf", &a);
	printf("Enter the value of variable b: ");
	scanf("%lf", &b);
	printf("Enter the value of variable c: ");
	scanf("%lf", &c);
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
				printf("All real numbers are solutions\n");
			else
				printf("No solution\n");
			return 0;
		}
		printf("root = %g\n", -c / b);
		return 0;
	}
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		double complex discriminant_sqrt = csqrt(discriminant);
		double complex root1 = (-b + discriminant_sqrt) / (2 * a);
		double complex root2 = (-b - discriminant_sqrt) / (2 * a);
		double i = cimag(root1);
		if (i >= 0)
			printf("root1 = %g + %gi\n", creal(root1), i);
		else
			printf("root1 = %g - %gi\n", creal(root1), fabs(i));
		i = cimag(root2);
		if (i >= 0)
			printf("root2 = %g + %gi\n", creal(root2), i);
		else
			printf("root2 = %g - %gi\n", creal(root2), fabs(i));
	}
	else
	{
		double discriminant_sqrt = sqrt(discriminant);
		double root1 = (-b + discriminant_sqrt) / (2 * a);
		double root2 = (-b - discriminant_sqrt) / (2 * a);
		printf("root1 = %g\n", root1);
		printf("root2 = %g\n", root2);
	}

	return 0;
}
