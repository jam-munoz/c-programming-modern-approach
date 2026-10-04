/* Write a program that displays the contents of a file as bytes and as characters. Have the user
specify the file name on the command line. Here’s what the output will look like when the
program is used to display the pun.c file of Section 2.1:
Offset				Bytes				Characters
------	-----------------------------	----------
    0	23 69 6E 63 6C 75 64 65 20 3C	#include <
   10	73 74 64 69 6F 2E 68 3E 0D 0A	stdio.h>..
   20	0D 0A 69 6E 74 20 6D 61 69 6E	..int main
   30	28 76 6F 69 64 29 0D 0A 7B 0D	(void)..{.
   40	0A 20 20 70 72 69 6E 74 66 28	. printf(
   50	22 54 6F 20 43 2C 20 6F 72 20	"To C, or
   60	6E 6F 74 20 74 6F 20 43 3A 20	not to C:
   70	74 68 61 74 20 69 73 20 74 68	that is th
   80	65 20 71 75 65 73 74 69 6F 6E	e question
   90	2E 5C 6E 22 29 3B 0D 0A 20 20	.\n");..
  100	72 65 74 75 72 6E 20 30 3B 0D	return 0;.
  110	0A 7D
 .}
Each line shows 10 bytes from the file, as hexadecimal numbers and as characters. The
number in the Offset column indicates the position within the file of the first byte on the
line. Only printing characters (as determined by the isprint function) are displayed;
other characters are shown as periods. Note that the appearance of a text file may vary,
depending on the character set and the operating system. The example above assumes that
pun.c is a Windows file, so 0D and 0A bytes (the ASCII carriage-return and line-feed
characters) appear at the end of each line. Hint: Be sure to open the file in "rb" mode.*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 10

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		if (argc < 2)
		{
			printf("Error. Too few arguments\nusage: my_hexdump <file>\n");
			exit(EXIT_FAILURE);
		}
		if (argc > 2)
		{
			printf("Error. Too many arguments\nusage: my_hexdump <file>\n");
			exit(EXIT_FAILURE);
		}
	}

	FILE	*fp;

	fp = fopen(argv[1], "rb");
	if (fp == NULL)
	{
		printf("Error. Cannot open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	printf("Offset\t%16s%23s\n------ ----------------------------- ----------\n", "Bytes", "Characters");
	char	buf[BUF_SIZE];
	int		n, i, j;
	for (i = 0;; i++)
	{
		n = fread(buf, sizeof(char), BUF_SIZE, fp);
		if (n != BUF_SIZE)
			break;
		printf("%6d %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X ", i * BUF_SIZE, buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9]);
		for (j = 0; j < BUF_SIZE; j++)
		{
			if (isprint((unsigned char)buf[j]))
				putchar(buf[j]);
			else
				putchar('.');
		}
		printf("\n");
	}
	if (n > 0)
	{
		printf("%6d ", i * BUF_SIZE);
		for (i = 0; i < n; i++)
			printf("%.2X ", buf[i]);
		for (; i < BUF_SIZE; i++)
			printf("  ");
		for (i = 0; i < BUF_SIZE - n; i++)
			printf(" ");
		for (i = 0; i < n; i++)
		{
			if (isprint((unsigned char)buf[i]))
				putchar(buf[i]);
			else
				putchar('.');
		}
		printf("\n");
	}
	fclose(fp);

}
