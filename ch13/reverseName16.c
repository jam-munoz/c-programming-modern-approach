/* Modify Programming Project 1 from Chapter 12 so that it includes the following function:
void reverse(char *message);
The function reverses the string pointed to by message. Hint: Use two pointers, one ini-
tially pointing to the first character of the string and the other initially pointing to the last
character. Have the function reverse these characters and then move the pointers toward
each other, repeating the process until the pointers meet. */
#include <stdio.h>
#include <string.h>
void reverse(char *message);

int main(void)
{
    char read[80];
    printf("Enter a message: ");
    fgets(read, sizeof(read), stdin);
    reverse(read);
    printf("%s", read);
    return 0;
}
void reverse(char *message)
{
    char papa[80];
    char *temp = papa;
    strcpy(temp, message);
    temp += strlen(temp) - 2;
    while(*message != '\n')
    {
        *message++ = *temp--;
    }
    return;
}