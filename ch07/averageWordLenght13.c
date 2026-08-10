/*Write a program that calculates the average word length for a sentence:
Enter a sentence: It was deja vu all over again. 24 - 7
Average word length: 3.4
For simplicity, your program should consider a punctuation mark to be part of the word to
which it is attached. Display the average word length to one decimal place.*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
float x = 0.0f, y = 1.0f;
char c;
printf ("Enter a sentence: "); 

while ((c = getchar()) != '\n')
{
        if (c == ' ')
            y++;
        else
            x++;
}  

printf ("%.2f %.2f %.2f\n", (x / y), x, y);
return 0;
}