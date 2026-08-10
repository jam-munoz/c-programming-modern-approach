/*Modify the repdigit.c program of Section 8.1 so that the user can enter more than one
number to be tested for repeated digits. The program should terminate when the user enters
a number that’s less than or equal to 0.*/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool digit_seen[10][10] = {false};
    int digit, times = 0, i;
    long n[10] = {0};

    //enter numbers
    do
    {
        printf("Enter a number: ");
        scanf("%ld", &n[times]);
        times++;
    } while (n[times-1] > 0);

    for (i = 0; n[i] > 0; i++)
    {
        while (n[i] > 0) 
        {
            digit = n[i] % 10;
            if (digit_seen[i][digit])
            {
                break;
            }
            digit_seen[i][digit] = true;
            n[i] /= 10;
        }
    }
    for (i = 0; i < (times - 1); i++)
    {
        if (n[i] > 0)
            printf("%d: Repeated digit(s)\n", (i+1));
        else
            printf("%d: No repeated digit\n", (i+1));
    }
    return 0;
}