/* Write a program that copies a text file from standard input to standard output, capitalizing
the first letter in each word.*/
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	int	c;
	bool	begin = true;

	while((c = getchar()) != EOF)
	{
		if (isspace(c) || ispunct(c))
		{
			begin = true;
		}
		else if (begin == true)
		{
			c = toupper(c);
			begin = false;
		}
		putchar(c);
	}
	return 0;
}
