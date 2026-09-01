/* Write the following function:
char *vstrcat(const char *first, ...);
All arguments of vstrcat are assumed to be strings, except for the last argument, which
must be a null pointer (cast to char * type). The function returns a pointer to a dynamically
allocated string containing the concatenation of the arguments. vstrcat should return a
null pointer if not enough memory is available. Hint: Have vstrcat go through the argu-
ments twice: once to determine the amount of memory required for the returned string and
once to copy the arguments into the string.*/
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *vstrcat(const char *first, ...)
{
	va_list	ap;
	int	len = 0;
	const char	*p = first;
	char	*str;

	va_start(ap, first);
	while (p != NULL)
	{
		len += strlen(p);
		p = va_arg(ap, char *);
	}
	va_end(ap);

	va_start(ap, first);
	str = malloc((len + 1) * sizeof(char));
	p = first;
	while (p != NULL)
	{
		strcat(str, p);
		p = va_arg(ap, char *);
	}
	va_end(ap);

	return str;
}

int main(void)
{
	char *str = vstrcat("las ", "papas ", "sociedad ", "anonima", NULL);
	printf("%s\n", str);
	free(str);
	return 0;
}
