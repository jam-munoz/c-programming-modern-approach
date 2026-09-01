/* Extend the function of Exercise 2 so that it allows two conversion specifications: %d and
%s. Each %d in the format string indicates an int argument, and each %s indicates a char
* (string) argument.*/

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
			else if (*(format + 1) == 's')
			{
				for (p = va_arg(ap, char *); *p != '\0'; p++, count++)
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
	char	str[] = "Hello, world";
	int		n;

	n = my_printf("%s\n", str);
	my_printf("%d\n", n);
	return 0;
}
