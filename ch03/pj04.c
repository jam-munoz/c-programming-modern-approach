/* Write a program that prompts the user to enter a telephone number in the form (xxx) xxx-
xxxx and then displays the number in the form xxx.xxx.xxx:
Enter phone number [(xxx) xxx-xxxx]: (404) 817-6900
You entered 404.817.6900*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	typedef struct
	{
		int area;
		int office;
		int line;
	}	phone;

	phone number;
	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	if (scanf(" (%d) %d-%d", &number.area, &number.office, &number.line) != 3)
	{
		printf("Wrong format\n");
		exit(EXIT_FAILURE);
	}
	printf("You entered %d.%d.%d\n", number.area, number.office, number.line);
}
