/* Use strtok to write the following function:
int count_words(char *sentence);
count_words returns the number of words in the string sentence, where a “word” is
any sequence of non-white-space characters. count_words is allowed to modify the string.*/
#include <string.h>

int count_words(char *sentence)
{
	char *p = strtok(sentence, " \t\n\v\f\r");
	int count = 0;

	while (p)
	{
		p = strtok(NULL, " \t\n\v\f\r");
		count++;
	}
	return count;
}
