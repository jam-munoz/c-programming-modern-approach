/*Write a program that counts the number of vowels (a, e, i, o, and u) in a sentence:
Enter a sentence: And that's the way it is.
Your sentence contains 6 vowels.*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
int i = 0;
char c;
printf ("Enter a sentence: ");
while ((c = getchar()) != '\n')
    switch (c)
    {
        case 'a': case 'e': case 'i': case 'o': case 'u': i++; break;
        default: break;
    }
printf ("Vowel number: %d\n", i);
return 0;
}