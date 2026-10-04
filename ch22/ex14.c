/* (a) Write your own version of the fgets function. Make it behave as much like the real
fgets function as possible; in particular, make sure that it has the proper return value. To
avoid conflicts with the standard library, don’t name your function fgets.*/
#include <stdio.h>

char *my_fgets(char *s, int n, FILE *stream)
{
	int i = 0;
	int c;

	n--;
	for (; i < n ; i++)
	{
		c = getc(stream);
		if (c == EOF)
		{
			if (i == 0)
				return NULL;
			break;
		}
		s[i] = c;
		if (s[i] == '\n')
		{
			i++;
			break;
		}
	}
	s[i] = '\0';

	return s;
}

//(b) Write your own version of fputs, following the same rules as in part (a).

int my_fputs(const char *s, FILE *stream)
{
	int	len = 0;
	int	i;

	while (s[len] != '\0')
		len++;
	i = fwrite(s, sizeof(char), len, stream);
	if (i != len)
		return EOF;
	
	return 1;
}
