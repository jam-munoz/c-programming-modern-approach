/* Write a program that converts all letters in a file to upper case. (Characters other than letters
shouldn’t be changed.) The program should obtain the file name from the command line and
write its output to stdout.*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE	*fp;
	int		c;

	if (argc != 2)
	{
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((c = getc(fp)) != EOF)
	{
		putchar(toupper(c));
	}
	fclose(fp);

	return 0;
}
