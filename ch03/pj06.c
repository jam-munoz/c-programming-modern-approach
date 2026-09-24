/*Modify the addfrac.c program of Section 3.2 so that the user enters both fractions at the
same time, separated by a plus sign:
Enter two fractions separated by a plus sign: 5/6+3/4
The sum is 38/24*/

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
	printf("Enter two fractions separated by a plus sign: ");
	scanf(" %d/%d+%d/%d", &a.num, &a.denom, &b.num, &b.denom);

	result.num = a.num * b.denom + b.num * a.denom;
	result.denom = a.denom * b.denom;
	printf("The sum is %d/%d\n", result.num, result.denom);

	return 0;
}
