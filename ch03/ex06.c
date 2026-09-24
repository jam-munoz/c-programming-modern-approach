/*Show how to modify the addfrac.c program of Section 3.2 so that the user is allowed to
enter fractions that contain spaces before and after each / character.*/

/* addfrac.c (Chapter 3, page 46) */
/* Adds two fractions */

#include <stdio.h>

int main(void)
{
	typedef struct
	{
		int num;
		int denom;
	}	fraction;

	fraction a, b, result;
	printf("Enter first fraction: ");
	scanf("%d / %d", &a.num, &a.denom);

	printf("Enter second fraction: ");
	scanf("%d / %d", &b.num, &b.denom);

	result.num = a.num * b.denom + b.num * a.denom;
	result.denom = a.denom * b.denom;
	printf("The sum is %d/%d\n", result.num, result.denom);

	return 0;
}
