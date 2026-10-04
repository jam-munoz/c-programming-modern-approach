/* (a) Write a program that counts the number of characters in a text file.
(b) Write a program that counts the number of words in a text file. (A “word” is any
sequence of non-white-space characters.)
(c) Write a program that counts the number of lines in a text file.
Have each program obtain the file name from the command line.*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		if (argc < 3)
		{
			printf("Error. Too few arguments\nusage: count [c/w/l] <file>\n");
			exit(EXIT_FAILURE);
		}
		if (argc > 3)
		{
			printf("Error. Too many arguments\nusage: count [c/w/l] <file>\n");
			exit(EXIT_FAILURE);
		}
	}
	if (argv[1][1] != '\0' || (argv[1][0] != 'c' && argv[1][0] != 'w' && argv[1][0] != 'l'))
	{
		printf("Error. Wrong specifier\nusage: count [c/w/l] <file>\n");
		exit(EXIT_FAILURE);
	}

	FILE	*fp;
	int		c;
	int		count = 0;

	fp = fopen(argv[2], "r");
	if (fp == NULL)
	{
		printf("Error. Cannot open file.\n");
		exit(EXIT_FAILURE);
	}
	if	(argv[1][0] == 'c')
	{
		while ((c = getc(fp)) != EOF)
		{
			count++;
		}
	}
	else if (argv[1][0] == 'w')
	{
		while ((c = getc(fp)) != EOF)
		{
			if (isspace(c))
			{
				while (isspace(c = getc(fp)))
					;
			}
			else
			{
				count++;
				while(!isspace(c = getc(fp)) && c != EOF)
					;
			}
		}
	}
	else if (argv[1][0] == 'l')
	{
		while ((c = getc(fp)) != EOF)
		{
			if (c == '\n')
			{
				count++;
			}
		}
		count++;
	}
	fclose(fp);
	printf("%d\n", count);
	return 0;
}

