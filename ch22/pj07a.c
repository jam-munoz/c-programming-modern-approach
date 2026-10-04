/* Of the many techniques for compressing the contents of a file, one of the simplest and fast-
est is known as run-length encoding. This technique compresses a file by replacing
sequences of identical bytes by a pair of bytes: a repetition count followed by a byte to be
repeated. For example, suppose that the file to be compressed begins with the following
sequence of bytes (shown in hexadecimal):
46 6F 6F 20 62 61 72 21 21 21 20 20 20 20 20
The compressed file will contain the following bytes:
01 46 02 6F 01 20 01 62 01 61 01 72 03 21 05 20
Run-length encoding works well if the original file contains many long sequences of identi-
cal bytes. In the worst case (a file with no repeated bytes), run-length encoding can actually
double the length of the file.
(a) Write a program named compress_file that uses run-length encoding to compress
a file. To run compress_file, we’d use a command of the form
compress_file original-file
compress_file will write the compressed version of original-file to original-file.rle.
For example, the command
compress_file foo.txt
will cause compress_file to write a compressed version of foo.txt to a file named
foo.txt.rle. Hint: The program described in Programming Project 6 could be useful
for debugging.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		if (argc < 2)
		{
			printf("Error. Too few arguments\nusage: compress_file <file>\n");
			exit(EXIT_FAILURE);
		}
		if (argc > 2)
		{
			printf("Error. Too many arguments\nusage: compress_file <file>\n");
			exit(EXIT_FAILURE);
		}
	}

	FILE	*fp_in, *fp_out;
	char	file_name[128];
	int		word_count, word, c;

	fp_in = fopen(argv[1], "rb");
	if (fp_in == NULL)
	{
		printf("Error. Cannot open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	snprintf(file_name, sizeof(file_name), "%.123s.rle", argv[1]);
	fp_out = fopen(file_name, "wb");
	if (fp_out == NULL)
	{
		printf("Error. Cannot create %s.\n", file_name);
		fclose(fp_in);
		exit(EXIT_FAILURE);
	}
	c = getc(fp_in);
	while (c != EOF)
	{
		word_count = 1;
		word = c;
		while (word_count < 255 && (c = getc(fp_in)) != EOF)
		{
			if (word != c)
				break;
			word_count++;
		}
		putc(word_count, fp_out);
		putc((unsigned char)word, fp_out);
	}
	fclose(fp_in);
	fclose(fp_out);

	return 0;
}
