/* Using isalpha and isalnum, write a function that checks whether a string has the syn-
tax of a C identifier (it consists of letters, digits, and underscores, with a letter or underscore
at the beginning).*/
#include <ctype.h>

int check_syntax(const char *str)
{
	if (*str != '_' && !isalpha((unsigned char)*str))
		return 0;
	str++;
	while (*str != '\0')
	{
		if (*str != '_' && !isalnum((unsigned char)*str))
			return 0;
		str++;
	}
	return 1;
}
