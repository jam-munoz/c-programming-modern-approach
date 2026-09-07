/* Write the following function:
char *max_pair(int num_pairs, ...);
The arguments of max_pair are assumed to be “pairs” of integers and strings; the value of num_pairs indicates how many
pairs will follow. (A pair consists of an int argument followed by a char * argument). The function searches the
integers to find the largest one; it then returns the string argument that follows it. Consider the following call:
max_pair(5, 180, "Seinfeld", 180, "I Love Lucy", 39, "The Honeymooners", 210, "All in the Family", 86, "The Sopranos")
The largest int argument is 210, so the function returns "All in the Family", which follows it in the argument list.*/
#include <stdarg.h>
#include <stdio.h>

char *max_pair(int num_pairs, ...)
{
	va_list	ap;
	int		largest;
	int		current;
	char	*str;

	if (num_pairs < 1)
		return NULL;

	va_start(ap, num_pairs);
	largest = va_arg(ap, int);
	str = va_arg(ap, char *);
	for (int i = 1; i < num_pairs; i++)
	{

		current = va_arg(ap, int);
		if (current > largest)
		{
			str = va_arg(ap, char *);
			largest = current;
		}
		else
			(void)va_arg(ap, char *);
	}
	va_end(ap);

	return (str);
}

int main(void)
{
	char *str = max_pair(5, 180, "Seinfeld", 180, "I Love Lucy", 39, "The Honeymooners", 210, "All in the Family", 86, "The Sopranos");
	printf("%s\n", str);
	return 0;
}
