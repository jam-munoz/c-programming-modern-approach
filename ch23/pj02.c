/* Write a program that copies a text file from standard input to standard output, removing all
white-space characters from the beginning of each line. A line consisting entirely of white-
space characters will not be copied.*/
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	int	c;
	bool	begin = true;

	while((c = getchar()) != EOF)
	{
		if (isspace(c) && begin == true)
			;
		else if (c == '\n')
		{
			putchar(c);
			begin = true;
		}
		else
		{
			begin = false;
			putchar(c);
		}
	}
	return 0;
}
