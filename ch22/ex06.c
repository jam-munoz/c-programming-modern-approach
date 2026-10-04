/* Write a call of printf that prints
1 widget
if the widget variable (of type int) has the value 1, and
n widgets
otherwise, where n is the value of widget. You are not allowed to use the if statement or
any other statement; the answer must be a single call of printf.*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error.\nusage: widget <number>\n");
		exit(EXIT_FAILURE);
	}
	int n;

	n = atoi(argv[1]);
	printf("%d widget%c\n", n, ('s' * (n != 1)));
}
