/*Modify Programming Project 5 from Chapter 7 so that it includes the following function:
int compute_scrabble_value(const char *word);
The function returns the SCRABBLE value of the string pointed to by word.*/ 

#include <stdio.h>
#include <ctype.h>
int compute_scrabble_value(const char *word);

int main(void)
{
    char word[16];
    printf("Enter a word: ");
    printf("Scrabble value: %d\n", compute_scrabble_value(fgets(word, sizeof(word), stdin)));
    return 0;
}
int compute_scrabble_value(const char *word)
{
    int i = 0;
    while (*word)
    {
        switch (toupper(*word))
        {
            case 'A': case 'E': case 'I': case 'L':
            case 'N': case 'O': case 'R': case 'S':
            case 'T': case 'U': i++; break;
            case 'D': case 'G': i += 2; break;
            case 'B': case 'C': case 'M': case 'P': i += 3; break;
            case 'F': case 'H': case 'V': case 'W':
            case 'Y': i += 4; break;
            case 'K': i += 5; break;
            case 'J': case 'X': i += 8; break;
            case 'Q': case 'Z': i += 10; break;
            default: break;
        }
        word++;
    }
    return i;
}