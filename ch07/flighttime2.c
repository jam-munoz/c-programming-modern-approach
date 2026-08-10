/*Modify Programming Project 8 from Chapter 5 so that the user enters a time using the 12-
hour clock. The input will have the form hours:minutes followed by either A, P, AM, or PM
(either lower-case or upper-case). White space is allowed (but not required) between the
numerical time and the AM/PM indicator. Examples of valid input:
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
char *departure = "Closest departure time is ";
char *arriving = ", arriving at ";
char *am = " a.m.";
char *pm = " p.m.";
printf ("Enter a 12-hour time (HH:mm AM/PM): ");
scanf ("%d:%d %c", &HH, &mm, &ampm);

if (HH <= 0 || HH >= 13)
    {
    printf ("Invalid time.\n");
    return 1;
    }
if (toupper(ampm) == 'A')
{
if (HH < 8)
    printf ("%s8:00%s%s10:16%s\n", departure, am, arriving, am);
else if (HH <= 9)
    printf ("%s9:43%s%s11:52%s\n", departure, am, arriving, am);
else if (HH <= 11)
    printf ("%s11:19%s%s13:31%s\n", departure, am, arriving, pm);
else if (HH <= 12)
    printf ("%s12:47%s%s3:00%s\n", departure, pm, arriving, pm);
}
else if (toupper(ampm) == 'P')
{
if (HH < 2)
    printf ("%s2:00%s%s4:08%s\n", departure, pm, arriving, pm);
else if (HH <= 3)
    printf ("%s3:45%s%s5:55%s\n", departure, pm, arriving, pm);
else if (HH < 7)
    printf ("%s7:00%s%s9:20%s\n", departure, pm, arriving, pm);
else if (HH <= 9)
    printf ("%s9:45%s%s11:58%s\n", departure, pm, arriving, pm);
else
    printf ("%s8:00%s%s10:16%s\n", departure, am, arriving, am);
}
return 0;
}