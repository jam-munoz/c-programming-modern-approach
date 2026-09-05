/* Write a program that counts the number of sentences in a text file (obtained from standard
input). Assume that each sentence ends with a ., ?, or ! followed by a white-space charac-
ter (including \n).*/
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int	c;
	int count = 0;

	(void)getchar();
	while((c = getchar()) != EOF)
	{
		if (c == '.' || c == '?' || c == '!')
		{
			c = getchar();
			if (isspace(c))
				count++;
			while ((c = getchar()) != EOF && isspace(c))
				;
		}
	}
	printf("Number of sentences: %d\n", count);
	return 0;
}
