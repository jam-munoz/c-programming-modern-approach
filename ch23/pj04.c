/* Write a program that prompts the user to enter a series of words separated by single spaces,
then prints the words in reverse order. Read the input as a string, and then use strtok to
break it into words.*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1024];
	char *words[512];
	char *p;
	int count = 0;

	printf("Enter a series of words separated by single spaces: ");
	fgets(str, sizeof(str), stdin);

	p = strtok(str, " \n");
	while (p != NULL)
	{
		words[count++] = p;
		p = strtok(NULL, " \n");
	}

	while (count > 0)
	{
		printf("%s", words[--count]);
		if (count > 0)
			putchar(' ');
	}
	putchar('\n');

	return 0;
}
