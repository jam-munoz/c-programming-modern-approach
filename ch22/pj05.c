/* The xor.c program of Section 20.1 refuses to encrypt bytes that—in original or encrypted
form—are control characters. We can now remove this restriction. Modify the program so
that the names of the input and output files are command-line arguments. Open both files in
binary mode, and remove the test that checks whether the original and encrypted characters
are printing characters.*/
/* xor.c (Chapter 20, page 515) */
/* Performs XOR encryption */

#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		printf("Error. Wrong number of arguments\n");
			exit(EXIT_FAILURE);
	}
	FILE	*fp_in, *fp_out;
	int		c;

	fp_in = fopen(argv[1], "rb");
	if (fp_in == NULL)
	{
		printf("Error. Cannot open %s.\n", argv[1]);
			exit(EXIT_FAILURE);
	}
	fp_out = fopen(argv[2], "wb");
	if (fp_out == NULL)
	{
		printf("Error. Cannot open %s.\n", argv[2]);
			exit(EXIT_FAILURE);
	}

	while ((c = getc(fp_in)) != EOF)
	{
		putc(c ^ KEY, fp_out);
	}
	fclose(fp_in);
	fclose(fp_out);
	return 0;
}
