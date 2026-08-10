/*Programming Project 1 in Chapter 4 asked you to write a program that displays a two-digit
number with its digits reversed. Generalize the program so that the number can have one,
two, three, or more digits. Hint: Use a do loop that repeatedly divides the number by 10,
stopping when it reaches 0.*/

#include <stdio.h>

int main(void)
{    
    int number, digits = 0;
    printf ("Enter a number: ");
    scanf ("%d", &number);
    if (number <= 0)
            return 1;
// calculate number of digits
    for (int numcopy = number; numcopy > 0; digits++)
        {
            numcopy = numcopy / 10;
        }
// declare array based on number of digits
    int reversal[digits];

// set numbers in reverse order
    for (int i = 0; i <= (digits - 1); i++)
        {
            reversal[i] = number % 10;
            number = number / 10;
        }
    printf ("The reversal is: ");
// print each number in order
    for (int i = 0; i <= (digits - 1); i++)
        {    
            printf ("%d", reversal[i]);
        }
    printf ("\n");
    return 0;
}