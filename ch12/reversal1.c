/* (a) Write a program that reads a message, then prints the reversal of the message:
Enter a message: Don't get mad, get even.
Reversal is: .neve teg ,dam teg t'noD
Hint: Read the message one character at a time (using getchar) and store the characters in
an array. Stop reading when the array is full or the character read is '\n'.
(b) Revise the program to use a pointer instead of an integer to keep track of the current
position in the array. */
#include <stdio.h>

int main(void)
{
    char c, read[100], *p;
    p = &read[0];
    printf("Enter a message: ");
    while ((c = getchar()) != '\n')
        *p++ = c;
    *p = '\0';
    while (p > &read[0])
        printf("%c", *--p);
    putchar('\n');
    return 0;
}