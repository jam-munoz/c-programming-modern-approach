/* Modify Programming Project 8 from Chapter 5 so that the times are stored in a single array.
The elements of the array will be structures, each containing a departure time and the corre-
sponding arrival time. (Each time will be an integer, representing the number of minutes
since midnight.) The program will use a loop to search the array for the departure time clos-
est to the time entered by the user.*/
#include <stdio.h>
struct time 
{
    int hours;
    int minutes;
};
struct time split_time(int total_minutes);

int main(void)
{
    int HH, mm, minutes, i = 0; 
    const struct flight 
    {
        int departure;
        int arrival;
    } times[] = 
    {
        {480, 616}, {583, 712}, {679, 811},  {767, 900}, 
        {840, 968}, {945, 1075}, {1140, 1280}, {1305, 1438}
    };

    printf ("Enter a 24-hour time (HH:mm): ");
    scanf ("%d:%d", &HH, &mm);
    if (HH < 0 || HH >= 24 || mm < 0 || mm >= 60)
    {
        printf ("Invalid time.\n");
        return -1;
    }
    minutes = (HH * 60) + mm;
    int maxsize = sizeof(times) / sizeof(times[0]);
    while (minutes > times[i].departure && i < maxsize)
        i++;
    if (i >= maxsize)
        i = 0;
    struct time departure_time = split_time(times[i].departure);
    struct time arrival_time = split_time(times[i].arrival);
    printf("Closest departure time is %d:%.2d, arriving at %d:%.2d\n", departure_time.hours, departure_time.minutes, arrival_time.hours, arrival_time.minutes);
    return 0;
}

struct time split_time(int total_minutes)
{
  struct time t;
  t.hours = (total_minutes / 60) % 24;
  t.minutes = total_minutes % 60;
  return t;
}