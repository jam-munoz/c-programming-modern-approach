/* Modify Programming Project 7 from Chapter 2 so that it includes the following function:
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);
The function determines the smallest number of $20, $10, $5, and $1 bills necessary to pay
the amount represented by the dollars parameter. The twenties parameter points to a
variable in which the function will store the number of $20 bills required. The tens,
fives, and ones parameters are similar. */

#include <stdio.h>

#define Q 25
#define D 10
#define N 5
#define P 1

void change_amount(int change, int *quarters, int *dimes, int *nickels, int *pennies);

int main(void)
{
    int owed;
    printf ("Change owed (in cents): ");
    scanf ("%d", &owed);
    int quarters, dimes, nickels, pennies;
    change_amount(owed, &quarters, &dimes, &nickels, &pennies);
    printf ("%d quarters, %d dimes, %d nickels, %d pennies \n", quarters, dimes, nickels, pennies);
}

void change_amount(int change, int *quarters, int *dimes, int *nickels, int *pennies)
{
    *quarters = change / Q;
    *dimes = change % Q / D;
    *nickels = (change % Q) %D / N;
    *pennies = ((change % Q) %D) %N / P;
}