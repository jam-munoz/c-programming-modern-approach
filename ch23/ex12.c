/* Many versions of <string.h> provide additional (nonstandard) functions, such as those
listed below. Write each function using only the features of the C standard.
(a) strdup(s) — Returns a pointer to a copy of s stored in memory obtained by calling
malloc. Returns a null pointer if enough memory couldn’t be allocated.
(b) stricmp(s1, s2) — Similar to strcmp, but ignores the case of letters.
(c) strlwr(s) — Converts upper-case letters in s to lower case, leaving other characters
unchanged; returns s.
(d) strrev(s) — Reverses the characters in s (except the null character); returns s.
(e) strset(s, ch) — Fills s with copies of the character ch; returns s.
If you test any of these functions, you may need to alter its name. Functions whose names
begin with str are reserved by the C standard.*/
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *s)
{
	int len = strlen(s);
	char *str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return NULL;

	strcpy(str, s);

	return str;
}

int my_stricmp(const char *s1, const char *s2)
{
	int c1, c2;
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
		{
			c1 = tolower(*s1);
			c2 = tolower(*s2);
			if (c1 != c2)
				return c1 - c2;
			else
			{
				s1++;
				s2++;
			}
		}
		else
		{
			s1++;
			s2++;
		}
	}
	return *s1 - *s2;
}

char *my_strlwr(char *s)
{
	char *p = s;
	while (*p != '\0')
	{
		*p = tolower((unsigned char)*p);
		p++;
	}
	return s;
}

char *my_strrev(char *s)
{
	int len = (int)strlen(s) - 1;
	char temp;
	for (int i = 0; i < len; i++, len--)
	{
		temp = s[i];
		s[i] = s[len];
		s[len] = temp;
	}
	return s;
}
char *my_strset(char *s, char ch)
{
	char *p = s;

	while (*p != '\0')
	{
		*p = ch;
		p++;
	}
	return s;
}
