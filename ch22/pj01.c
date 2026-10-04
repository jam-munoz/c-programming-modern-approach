/* Extend the canopen.c program of Section 22.2 so that the user may put any number of
file names on the command line:
canopen foo bar baz
The program should print a separate can be opened or can't be opened message for
each file. Have the program terminate with status EXIT_FAILURE if one or more of the
files can’t be opened. */
/* canopen.c (Chapter 22, page 547) */
/* Checks whether a file can be opened for reading */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE	*fp;
	bool	canopen;

	if (argc < 2)
	{
		printf("usage: canopen filename\n");
		exit(EXIT_FAILURE);
	}

	canopen = true;

	for (int i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			printf("%s can't be opened\n", argv[i]);
			canopen = false;
		}
		else
		{
			printf("%s can be opened\n", argv[i]);
			fclose(fp);
		}
	}
	if (canopen == false)
	{
		exit(EXIT_FAILURE);
	}
	return 0;
}
