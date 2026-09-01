/* Write a simplified version of printf in which the only conversion specification is %d, and
all arguments after the first are assumed to have int type. If the function encounters a %
character that’s not immediately followed by a d character, it should ignore both characters.
The function should use calls of putchar to produce all output. You may assume that the
format string doesn’t contain escape sequences. */
#include <stdarg.h>
#include <stdio.h>

int my_printf(const char *format, ...)
{
	va_list	ap;
	int		count = 0;
	int		temp;
	char	nbr[12];
	char	*p;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) == 'd')
			{
				temp = va_arg(ap, int);
				sprintf(nbr, "%d", temp);
				for (p = nbr; *p != '\0'; p++, count++)
				{
					putchar(*p);
				}
			}
			format +=2;
		}
		else
		{
			putchar(*format);
			format++;
			count++;
		}
	}
	va_end(ap);
	return count;
}

int main(void)
{
	int	n;

	n = my_printf("Hello, world\n");
	my_printf("%d\n", n);
	return 0;
}
