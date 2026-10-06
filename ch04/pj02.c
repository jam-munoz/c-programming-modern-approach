/* Extend the program in Programming Project 1 to handle three-digit numbers.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	printf("Enter a two or three-digit number: ");
	if (scanf(" %d", &n) != 1 || n > 999 || n < 10)
	{
		printf("Wrong format\n");
		exit(EXIT_FAILURE);
	}
	printf("The reversal is: %d%d", n % 10, n / 10 % 10);
	if (n > 99)
		printf("%d", n / 100);
	putchar('\n');
}
