/*Modify the repdigit.c program of Section 8.1 so that it prints a table showing how
many times each digit appears in the number:
Enter a number: 41271092
Digit:       0 1 2 3 4 5 6 7 8 9
Occurrences: 1 2 2 0 1 0 0 1 0 1 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    //bool digit_seen[10] = {false};
    int c[10] = {0};
    int digit, i;
    long n;
    printf("Enter a number: ");
    scanf("%ld", &n);
    while (n > 0) 
    {
        digit = n % 10;
        c[digit] += 1;
        n /= 10;
    }

    printf("Digit:       0 1 2 3 4 5 6 7 8 9\n");
    printf("Occurrences: ");
    for (i = 0; i < 10; i++)
        printf("%d ", c[i]);
    printf("\n");
    
    return 0;
}