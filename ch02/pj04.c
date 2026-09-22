/*Write a program that asks the user to enter a dollars-and-cents amount, then displays the
amount with 5% tax added:
Enter an amount: 100.00
With tax added: $105.00*/

#include <stdio.h>

int main(void)
{
	float price;
	printf ("Enter an ammount: ");
	scanf ("%f", &price);
	float tax = price / 20.0f;
	printf ("With tax added: $%.2f\n", (price + tax));
	return 0;
}
