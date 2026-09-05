/* Suppose that money is deposited into a savings account and left for t years. Assume that the
annual interest rate is r and that interest is compounded continuously. The formula A(t) =
Pert can be used to calculate the final value of the account, where P is the original amount
deposited. For example, $1000 left on deposit for 10 years at 6% interest would be worth
$1000 × e.06×10 = $1000 × e.6 = $1000 × 1.8221188 = $1,822.12. Write a program that dis-
plays the result of this calculation after prompting the user to enter the original amount
deposited, the interest rate, and the number of years.*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double p, r, t;
	printf("Enter deposit amount: ");
	if (scanf("%lf", &p) != 1)
	{
		printf("Error. Format not valid.\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter interest rate: ");
	if (scanf("%lf", &r) != 1)
	{
		printf("Error. Format not valid.\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter number of years: ");
	if (scanf("%lf", &t) != 1)
	{
		printf("Error. Format not valid.\n");
		exit(EXIT_FAILURE);
	}
	r /= 100;
	printf("Result: %.2lf\n", p * exp(r * t));
}
