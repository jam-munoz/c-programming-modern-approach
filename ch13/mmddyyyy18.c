/* Write a program that accepts a date from the user in the form mm/dd/yyyy and then dis-
plays it in the form month dd, yyyy, where month is the name of the month:
Enter a date (mm/dd/yyyy): 2/17/2011
You entered the date February 17, 2011
Store the month names in an array that contains pointers to strings.*/
#include <stdio.h>

int main(void)
{
    int mm, dd, yyyy;
    char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);
    printf("You entered the date %s %d, %d\n", month[mm-1], dd, yyyy);
    return 0;
}