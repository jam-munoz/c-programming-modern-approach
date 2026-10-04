/* Write the following function:
int line_length(const char *filename, int n);
The function should return the length of line n in the text file whose name is filename
(assuming that the first line in the file is line 1). If the line doesn’t exist, the function should
return 0.*/
#include <stdio.h>

int line_length(const char *filename, int n)
{
	FILE	*fp;
	int		len = 0;
	int		c;

	fp = fopen(filename, "r");
	for (int i = 1; i < n; i++)
	{
		fscanf(fp, "%*[^\n]");
		if (feof(fp))
		{
			fclose(fp);
			return 0;
		}
		getc(fp);
	}
	while ((c = getc(fp)) != '\n'  && c != EOF)
	{
		len++;
	}
	fclose(fp);
	return (len);
}

int main(void)
{
	printf("%d\n", line_length("ex13.c", 13));
}
