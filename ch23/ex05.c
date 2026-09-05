/* Using isxdigit, write a function that checks whether a string represents a valid hexadec-
imal number (it consists solely of hexadecimal digits). If so, the function returns the value of
the number as a long int. Otherwise, the function returns –1.*/
#include <ctype.h>
#include <stdio.h>

long check_hex(const char *str)
{
	const char *p;
	long n;

	p = str;
	while (*p != '\0')
	{
		if (!isxdigit((unsigned char)*p))
			return -1;
		p++;
	}
	if (sscanf(str, "%x", &n))
		return n;
	return -1;
}
