/* Write a program that prompts the user to enter two dates, then prints the difference between
them, measured in days. Hint: Use the mktime and difftime functions.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int m, d, y, n;
	struct tm t1 = { 0 };
	struct tm t2 = { 0 };
	time_t date1, date2;
	long difference;

	printf("Enter a date (month, day, and year): ");
	n = scanf("%d, %d, %d", &m, &d, &y);
	if (n != 3 || m < 1 || d < 1 || y < 1900 || m > 12 || d > 31 || y > 2100 || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) ||
    (m == 2 && d > 29))
	{
		printf("Error. Wrong date format.\n");
		exit(EXIT_FAILURE);
	}

	t1.tm_mday = d;
	t1.tm_mon = m - 1;
	t1.tm_year = y - 1900;
	t1.tm_isdst = -1;
	date1 = mktime(&t1);

	printf("Enter another date (month, day, and year): ");
	n = scanf("%d, %d, %d", &m, &d, &y);
	if (n != 3 || m < 1 || d < 1 || y < 1900 || m > 12 || d > 31 || y > 2100 || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) ||
    (m == 2 && d > 29))
	{
		printf("Error. Wrong date format.\n");
		exit(EXIT_FAILURE);
	}
	t2.tm_mday = d;
	t2.tm_mon = m - 1;
	t2.tm_year = y - 1900;
	t2.tm_isdst = -1;
	date2 = mktime(&t2);

	difference = (long)(difftime(date2, date1) / 86400);

	printf("%ld days have passed\n", difference);
}
