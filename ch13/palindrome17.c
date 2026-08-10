/* Modify Programming Project 2 from Chapter 12 so that it includes the following function:
bool is_palindrome(const char *message);
The function returns true if the string pointed to by message is a palindrome. */
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool is_palindrome(const char *message);

int main(void)
{
    char read[80];
    printf("Enter a message: ");
    fgets(read, sizeof(read), stdin);
    if (is_palindrome(read))
        printf("Palindrome.\n");
    else printf("Not a palindrome.\n");
    return 0;
}

bool is_palindrome(const char *message)
{
    bool palindrome = true;
    char one[80];
    char *p = one;
    while (*message != '\n')
    {
        if (isalpha(*message))
            *p++ = tolower(*message);
        message++;
    }
    *p-- = '\0';
    for (int i = 0; i < strlen(one); p--, i++)
    {
        if (*p != one[i])
            palindrome = false;
    }
    return palindrome;
}