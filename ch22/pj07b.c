/*(b) Write a program named uncompress_file that reverses the compression performed
by the compress_file program. The uncompress_file command will have the form
uncompress_file compressed-file
compressed-file should have the extension .rle. For example, the command
uncompress_file foo.txt.rle
will cause uncompress_file to open the file foo.txt.rle and write an uncom-
pressed version of its contents to foo.txt. uncompress_file should display an error
message if its command-line argument doesn’t end with the .rle extension.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		if (argc < 2)
		{
			printf("Error. Too few arguments\nusage: uncompress_file <file>\n");
			exit(EXIT_FAILURE);
		}
		if (argc > 2)
		{
			printf("Error. Too many arguments\nusage: uncompress_file <file>\n");
			exit(EXIT_FAILURE);
		}
	}

	FILE	*fp_in, *fp_out;
	char	file_name[128];
	int		word_count, word, i;

	fp_in = fopen(argv[1], "rb");
	if (fp_in == NULL)
	{
		printf("Error. Cannot open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	int		len = strlen(argv[1]) - 4;
	if (len < 1 || strcmp(".rle", &argv[1][len]) != 0)
	{
		printf("Error. File must have .rle extension.\n");
		fclose(fp_in);
		exit(EXIT_FAILURE);
	}
	snprintf(file_name, sizeof(file_name), "%.*s", len, argv[1]);
	fp_out = fopen(file_name, "wb");
	if (fp_out == NULL)
	{
		printf("Error. Cannot create %s.\n", file_name);
		fclose(fp_in);
		exit(EXIT_FAILURE);
	}
	while ((word_count = getc(fp_in)) != EOF)
	{
		word = getc(fp_in);
		if (word == EOF)
			break;
		for (i = 0; i < word_count; i++)
			putc((unsigned char)word, fp_out);
	}
	fclose(fp_in);
	fclose(fp_out);

	return 0;
}
