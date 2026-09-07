/* Write a function that, when passed a year, returns a time_t value representing 12:00 a.m.
on the first day of that year.*/
#include <time.h>
#include <stdio.h>

time_t first_of_the_year(int year)
{
	struct tm t = { 0 };
	t.tm_year = year - 1900;
    t.tm_mday = 1;
    t.tm_isdst = -1;
	return mktime(&t);
}

int main(void)
{
    time_t t = first_of_the_year(1994);

    printf("%s", ctime(&t));
}
