/* Write a program that calculates how many digits a number contains:
Enter a number: 374
The number 374 has 3 digits
You may assume that the number has no more than four digits. Hint: Use if statements to
test the number. For example, if the number is between 0 and 9, it has one digit. If the num-
ber is between 10 and 99, it has two digits.*/

#include <stdio.h>

int	digit_count(int nb);

int main(void)
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	printf("The number %d has %d digit%c\n", n, digit_count(n), (-9 > n || n > 9 ? 's' : '\0'));
}

int	digit_count(int nb)
{
	unsigned int	n;

	n = nb;
	if (nb < 0)
		n = -n;
	if (n < 10)
		return (1);
	if (n < 100)
		return (2);
	if (n < 1000)
		return (3);
	if (n < 10000)
		return (4);
	if (n < 100000)
		return (5);
	if (n < 1000000)
		return (6);
	if (n < 10000000)
		return (7);
	if (n < 100000000)
		return (8);
	if (n < 1000000000)
		return (9);
	return (10);
}
