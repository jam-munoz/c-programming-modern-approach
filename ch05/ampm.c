#include <stdio.h>

/*Write a program that asks the user for a 24-hour time, then displays the time in 12-hour form:
Enter a 24-hour time: 21:11
Equivalent 12-hour time: 9:11 PM
Be careful not to display 12:00 as 0:00.*/
int main ()
{
    int HH, mm;
    char ampm;
    printf ("Enter a 24-hour time (HH:mm): ");
    scanf ("%d:%d", &HH, &mm);

    if (HH < 12 && HH >= 0 && mm < 60)
        ampm = 'A';
    else if (HH > 12 && HH < 24 && mm < 60)
    {
        ampm = 'P';
        HH = HH - 12;
    }
    else if (HH == 12 && mm < 60) 
        ampm = 'P';
    else 
    {
        printf ("Invalid time.\n");
        return 1;
    } 

    printf ("Equivalent 12-hour time: %d:%.2d ", HH, mm);
    printf ("%cM\n", ampm);
    return 0;
}