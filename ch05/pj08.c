/* The following table shows the daily flights from one city to another:
Departure time		Arrival time
8:00 a.m.			10:16 a.m.
9:43 a.m.			11:52 a.m.
11:19 a.m.			1:31 p.m.
12:47 p.m.			3:00 p.m.
2:00 p.m.			4:08 p.m.
3:45 p.m.			5:55 p.m.
7:00 p.m.			9:20 p.m.
9:45 p.m.			11:58 p.m.
Write a program that asks user to enter a time (expressed in hours and minutes, using the 24-
hour clock). The program then displays the departure and arrival times for the flight whose
departure time is closest to that entered by the user:
Enter a 24-hour time: 13:15
Closest departure time is 12:47 p.m., arriving at 3:00 p.m.
Hint: Convert the input into a time expressed in minutes since midnight, and compare it to
the departure times, also expressed in minutes since midnight. For example, 13:15 is 13 ×
60 + 15 = 795 minutes since midnight, which is closer to 12:47 p.m. (767 minutes since
midnight) than to any of the other departure times. */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int hour;
	int minutes;
	const char *departure = "Closest departure time is ";
	const char *arriving = ", arriving at ";
	const char *am = " a.m.";
	const char *pm = " p.m.";

	printf("Enter a 24-hour time (HH:mm): ");
	if (scanf(" %d:%d", &hour, &minutes) != 2)
	{
		printf("Wrong format.\n");
		exit(EXIT_FAILURE);
	}
	if (hour < 0 || hour >= 24 || minutes < 0 || minutes > 59)
	{
		printf ("Invalid time.\n");
		exit(EXIT_FAILURE);
	}
	else if (hour < 8)
		printf ("%s8:00%s%s10:16%s\n", departure, am, arriving, am);
	else if (hour <= 9 && minutes < 43)
		printf ("%s9:43%s%s11:52%s\n", departure, am, arriving, am);
	else if (hour <= 11 && minutes < 19)
		printf ("%s11:19%s%s13:31%s\n", departure, am, arriving, pm);
	else if (hour <= 12 && minutes < 47)
		printf ("%s12:47%s%s3:00%s\n", departure, pm, arriving, pm);
	else if (hour < 14)
		printf ("%s2:00%s%s4:08%s\n", departure, pm, arriving, pm);
	else if (hour <= 15 && minutes < 45)
		printf ("%s3:45%s%s5:55%s\n", departure, pm, arriving, pm);
	else if (hour < 19)
		printf ("%s7:00%s%s9:20%s\n", departure, pm, arriving, pm);
	else if (hour <= 21 && minutes < 45)
		printf ("%s9:45%s%s11:58%s\n", departure, pm, arriving, pm);
	else
		printf ("%s8:00%s%s10:16%s\n", departure, am, arriving, am);
	return 0;
}
