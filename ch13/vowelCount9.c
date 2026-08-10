/*Modify Programming Project 10 from Chapter 7 so that it includes the following function:
int compute_vowel_count(const char *sentence);
The function returns the number of vowels in the string pointed to by the sentence parameter. */

#include <stdio.h>
#include <ctype.h>
int compute_vowel_count(const char *sentence);

int main(void)
{
    char sentence[80];
    printf ("Enter a sentence: ");
    printf ("Vowel number: %d\n", compute_vowel_count(fgets(sentence, sizeof(sentence), stdin)));
    return 0;
}
int compute_vowel_count(const char *sentence)
{
    int i = 0;
    while (*sentence)
    {
        switch (*sentence)
        {
            case 'a': case 'e': case 'i': case 'o': case 'u': i++; break;
            default: break;
        }
        sentence++;
    }
    return i;    
}