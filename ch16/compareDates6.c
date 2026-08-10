/* Modify Programming Project 9 from Chapter 5 so that each date entered by the user is
stored in a date structure (see Exercise 5). Incorporate the compare_dates function of Exercise 5 into your program.*/
#include <stdbool.h>
#include <stdio.h>
/* Write the following functions, assuming that the date structure contains three members:
month, day, and year (all of type int).*/
struct date
{
    int month;
    int day;
    int year;
};
int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(void) 
{
    int i;
    struct date d1, d2;
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);
    i = compare_dates(d1, d2);
    switch(i)
    {
        case -1: printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
            break;
        case 0: printf("%d/%d/%.2d is equal to %d/%d/%.2d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
            break;
        case 1: printf("%d/%d/%.2d is later than %d/%d/%.2d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
            break;
        default: printf("ERROR\n"); break;
    }
    return 0;
}
//(a) Returns the day of the year (an integer between 1 and 366) that corresponds to the date d.*/
int day_of_year(struct date d)
{
const int month_days[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
  bool leap = false;
  if (d.month < 2)
    return d.day;
  if (d.month == 2)
    return d.day + month_days[d.month-2];
  if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0))
    leap = true;
  if (leap == true)
    return d.day + 1 + month_days[d.month-2];
  return d.day + month_days[d.month-2];
}
//(b) Returns –1 if d1 is an earlier date than d2, +1 if d1 is a later date than d2, and 0 if d1 and d2 are the same.
int compare_dates(struct date d1, struct date d2)
{
  if (d1.year < d2.year)
    return -1;
  if (d1.year > d2.year)
    return 1;
  int d1day = day_of_year(d1);
  int d2day = day_of_year(d2);
  if (d1day < d2day)
    return -1;
  if (d1day > d2day)
    return 1;
  return 0;
}