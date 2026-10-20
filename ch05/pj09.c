/* Write a program that prompts the user to enter two dates and then indicates which date
comes earlier on the calendar:
Enter first date (mm/dd/yy): 3/6/08
Enter second date (mm/dd/yy): 5/17/07
5/17/07 is earlier than 3/6/08*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	typedef struct
	{
		int m;
		int d;
		int y;
	}	date;

	date d1, d2;
	int earlier;
	printf("Enter first date (mm/dd/yy): ");
	if (scanf(" %d/%d/%d", &d1.m, &d1.d, &d1.y) != 3 || d1.m < 1 || d1.m > 12 || d1.d < 1 || d1.d > 31)
	{
		printf("Wrong format.\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter second date (mm/dd/yy): ");
	if (scanf(" %d/%d/%d", &d2.m, &d2.d, &d2.y) != 3 || d2.m < 1 || d2.m > 12 || d2.d < 1 || d2.d > 31)
	{
		printf("Wrong format.\n");
		exit(EXIT_FAILURE);
	}
	earlier = d1.y - d2.y;
	if (earlier == 0)
	{
		earlier = d1.m - d2.m;
		if (earlier == 0)
			earlier = d1.d - d2.d;
	}
	if (earlier > 0)
	{
		date temp = d1;
		d1 = d2;
		d2 = temp;
	}
	if (earlier == 0)
		printf("Both dates are equal.\n");
	else
		printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d\n", d1.m, d1.d, d1.y, d2.m, d2.d, d2.y);
}
