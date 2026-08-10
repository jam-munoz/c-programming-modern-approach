/* (a) Write a program that reads a message, then checks whether it’s a palindrome (the letters
in the message are the same from left to right as from right to left):
Enter a message: He lived as a devil, eh?
Palindrome
Enter a message: Madam, I am Adam.
Not a palindrome
Ignore all characters that aren’t letters. Use integer variables to keep track of positions in the array.
(b) Revise the program to use pointers instead of integers to keep track of positions in the array. */
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool palindrome = true;
    char c, read[80], *p, *q;
    p = &read[0];
    q = &read[0];
    printf("Enter a message: ");
    while ((c = getchar()) != '\n')
    {
        if (isalpha(c))
            *p++ = c;
    }
    *p = '\0';
    while (--p > q)
    {
        if (*p != *q)
            palindrome = false;
        q++;
    }
    if (palindrome)
        printf("Palindrome.\n");
    else printf("Not a palindrome.\n");
    return 0;
}