/* Write a program that copies a text file from standard input to standard output, replacing each
control character (other than \n) by a question mark.*/
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int	c;

	while((c = getchar()) != EOF)
	{
		if (c != '\n' && iscntrl(c))
		{
			c = '?';
		}
		putchar(c);
	}
	return 0;
}
