/*Write a program that asks the user for a 12-hour time, then displays the time in 24-hour
form:
Enter a 12-hour time: 9:11 PM
Equivalent 24-hour time: 21:11
Examples of valid input:
1:15P
1:15PM
1:15p
1:15pm
1:15 P
1:15 PM
1:15 p
1:15 pm
You may assume that the input has one of these forms; there is no need to test for errors.*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
int HH, mm;
char ampm;
printf ("Enter a 12-hour time (HH:mm AM/PM): ");
scanf ("%d:%d %c", &HH, &mm, &ampm);

if (HH == 12)
    HH -= 12;
if (toupper(ampm) == 'P')
    HH += 12;
printf ("Equivalent 24-hour time: %d:%d\n", HH, mm);
return 0;
}