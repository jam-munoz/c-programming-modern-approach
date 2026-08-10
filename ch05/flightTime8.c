#include <stdio.h>

int main(void)
{
int HH; 
char *departure = "Closest departure time is ";
char *arriving = ", arriving at ";
char *am = " a.m.";
char *pm = " p.m.";
printf ("Enter a 24-hour time (HH:mm): ");
scanf ("%d", &HH);
if (HH <= 0 || HH >= 24)
    {
    printf ("Invalid time.\n");
    return 1;
    }
else if (HH < 8)
    printf ("%s8:00%s%s10:16%s\n", departure, am, arriving, am);
else if (HH <= 9)
    printf ("%s9:43%s%s11:52%s\n", departure, am, arriving, am);
else if (HH <= 11)
    printf ("%s11:19%s%s13:31%s\n", departure, am, arriving, pm);
else if (HH <= 12)
    printf ("%s12:47%s%s3:00%s\n", departure, pm, arriving, pm);
else if (HH < 14)
    printf ("%s2:00%s%s4:08%s\n", departure, pm, arriving, pm);
else if (HH <= 15)
    printf ("%s3:45%s%s5:55%s\n", departure, pm, arriving, pm);
else if (HH < 19)
    printf ("%s7:00%s%s9:20%s\n", departure, pm, arriving, pm);
else if (HH <= 21)
    printf ("%s9:45%s%s11:58%s\n", departure, pm, arriving, pm);
else
    printf ("%s8:00%s%s10:16%s\n", departure, am, arriving, am);
return 0;
}