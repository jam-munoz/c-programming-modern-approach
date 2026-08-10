/*Write a declaration for a two-dimensional array named temperature_readings that
stores one month of hourly temperature readings. (For simplicity, assume that a month has
30 days.) The rows of the array should represent days of the month; the columns should rep-
resent hours of the day.*/

#include <stdio.h>

int main(void)
{
    const int temperature_readings[30][24]
    float average = 0.0f;
    int i, n; 
    for (n = 0; n < 30; n++)
    {
        for (i = 0; i < 24; i++)
            average += temperature readings[n][i];
    }
    printf ("Monthly average: %.2f", (average / 720))
}