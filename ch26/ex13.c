/* Section 26.3 described some of the ISO 8601 date and time formats. Here are a few more:
(a) Year followed by day of year: YYYY–DDD, where DDD is a number between 001 and 366
(b) Year, week, and day of week: YYYY–Www–D, where ww is a number between 01 and
53, and D is a digit between 1 through 7, beginning with Monday and ending with Sunday
(c) Combined date and time: YYYY–MM–DDThh:mm:ss
Give strftime strings that correspond to each of these formats.*/
#include <stdio.h>
#include <time.h>

int main(void)
{
	char date_time[21];
	time_t current = time(NULL);
    struct tm *ptr = localtime(&current);

	strftime(date_time, sizeof(date_time),"%Y-%j", ptr);
    printf("%s\n", date_time);
	strftime(date_time, sizeof(date_time),"%Y-W%W-%u", ptr);
    printf("%s\n", date_time);
	strftime(date_time, sizeof(date_time),"%FT-%T", ptr);
    printf("%s\n", date_time);
}
