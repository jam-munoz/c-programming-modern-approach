/* Write a program that asks the user to enter a U.S. dollar amount and then shows how to pay
that amount using the smallest number of $20, $10, $5, and $1 bills:
Enter a dollar amount: 93
$20 bills: 4
$10 bills: 1
$5 bills: 0
$1 bills: 3*/

#include <stdio.h>

int main(void)
{
	int dollars;
	typedef struct
	{
		int twenty;
		int ten;
		int five;
		int one;
	}	bill;

	bill bills = { 0 };
	printf("Enter a dollar amount: ");
	scanf("%d", &dollars);
	if (dollars >= 20)
	{
		bills.twenty = dollars / 20;
		dollars %= 20;
	}
	if (dollars >= 10)
	{
		bills.ten = dollars / 10;
		dollars %= 10;
	}
	if (dollars >= 5)
	{
		bills.five = dollars / 5;
		dollars %= 5;
	}
	bills.one += dollars;
	printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n", bills.twenty, bills.ten, bills.five, bills.one);
}
