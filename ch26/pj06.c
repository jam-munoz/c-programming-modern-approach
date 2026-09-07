/* Write programs that display the current date and time in each of the following formats. Use
strftime to do all or most of the formatting.
(a) Sunday, June 3, 2007 05:48p
(b) Sun, 3 Jun 07 17:48
(c) 06/03/07 5:48:34 PM*/

#include <stdio.h>
#include <time.h>

int main(void)
{
	char	date_time[36];
	time_t	current = time(NULL);
    struct tm	*ptr = localtime(&current);
	char	am_or_pm = 'a';

	strftime(date_time, sizeof(date_time),"%A, %B %e, %Y %I:%M", ptr);
	if (ptr->tm_hour > 11)
		am_or_pm = 'p';
	printf("%s%c\n", date_time, am_or_pm);

	strftime(date_time, sizeof(date_time),"%a, %e %b %y %H:%M", ptr);
	printf("%s\n", date_time);
	strftime(date_time, sizeof(date_time),"%x %r", ptr);
	printf("%s\n", date_time);
}
