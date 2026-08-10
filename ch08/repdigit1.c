/*Modify the repdigit.c program of Section 8.1 so that it shows which digits (if any)
were repeated:
Enter a number: 939577
Repeated digit(s): 7 9*/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool digit_seen[10] = {false};
    int c[10];
    int digit, i = 0;
    long n;
    printf("Enter a number: ");
    scanf("%ld", &n);
    while (n > 0) 
    {
        digit = n % 10;
        if (digit_seen[digit])
        {
            c[i] = digit;
            i++;
            //break;
        }
        digit_seen[digit] = true;
        n /= 10;
    }
    //if (n > 0)
    //{
        printf("Repeated digit(s): ");
        for (i = 0; i < 10; i++)
            if (c[i] != 0)
                printf("%d ", c[i]);
        printf("\n");
    //}
    //else
    //    printf("No repeated digit\n");
    return 0;
}