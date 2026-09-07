/* Write a program that prompts the user for a date (month, day, and year) and an integer n,
then prints the date that’s n days later.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int m, d, y, n;
	char date_time[21];
	printf("Enter a date (month, day, and year): ");
	n = scanf("%d, %d, %d", &m, &d, &y);
	if (n != 3 || m < 1 || d < 1 || y < 1900 || m > 12 || d > 31 || y > 2100 || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) ||
    (m == 2 && d > 29))
	{
		printf("Error. Wrong date format.\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter how many days passed: ");
	scanf("%d", &n);
	if (n < 0)
	{
		printf("Error. Wrong number of days.\n");
		exit(EXIT_FAILURE);
	}

	struct tm t = { 0 };
	t.tm_mday = d + n;
	t.tm_mon = m - 1;
	t.tm_year = y - 1900;
	t.tm_isdst = -1;
	mktime(&t);

	strftime(date_time, sizeof(date_time), "%D\n", &t);
	printf("Date %d day%c later = %s", n, 's' * (n != 1), date_time);
}
