/* Use strchr to write the following function:
int numchar(const char *s, char ch);
numchar returns the number of times the character ch occurs in the string s.*/
#include <string.h>

int numchar(const char *s, char ch)
{
	int count = 0;
	const char *p;

	p = strchr(s, ch);

	while (p != NULL)
	{
		count++;
		p = strchr(p + 1, ch);
	}
	return count;
}
