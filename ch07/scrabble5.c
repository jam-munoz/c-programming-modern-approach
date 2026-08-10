/*In the SCRABBLE Crossword Game, players form words using small tiles, each containing
a letter and a face value. The face value varies from one letter to another, based on the let-
ter’s rarity. (Here are the face values: 1: AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY, 5: K,
8: JX, 10: QZ.) Write a program that computes the value of a word by summing the values
of its letters:
Enter a word: pitfall
Scrabble value: 12
Your program should allow any mixture of lower-case and upper-case letters in the word.
Hint: Use the toupper library function.*/ 

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;
    int i = 0;
    printf("Enter a word: ");
    while ((c = getchar()) != '\n')
    {
        switch (toupper(c))
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
    }
    printf("Scrabble value: %d\n", i);
    return 0;
}