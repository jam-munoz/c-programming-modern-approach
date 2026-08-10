/* Modify Programming Project 11 from Chapter 7 so that it includes the following function:
void reverse_name(char *name);
The function expects name to point to a string containing a first name followed by a last
name. It modifies the string so that the last name comes first, followed by a comma, a space,
the first initial, and a period. The original string may contain extra spaces before the first
name, between the first and last names, and after the last name.*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>
void reverse_name(char *name);

int main(void)
{
    char name[80];
    printf ("Enter a first and last name: ");
    fgets(name, sizeof(name), stdin);
    reverse_name(name);
    printf ("%s\n", name);
    return 0;
}
void reverse_name(char *name)
{
    char initial;
    char temp[80];
    char *p = temp;
    strcpy(temp, name);
    while (*p && !isupper(*p))
        p++;
    initial = *p;
    p++;
    while (*p && !isupper(*p))
        p++;
    strcpy(name, p);
    while (isalpha(*name))
        name++;
    *name++ = ' ';
    *name++ = initial;
    *name++ = '.';
    *name = '\0';
    return;
}