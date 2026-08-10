/*Modify Programming Project 13 from Chapter 7 so that it includes the following function:
double compute_average_word_length(const char *sentence);
The function returns the average length of the words in the string pointed to by sentence.*/
#include <stdio.h>
double compute_average_word_length(const char *sentence);

int main(void)
{
    char sentence[80];
    printf ("Enter a sentence: "); 
    fgets(sentence, sizeof(sentence), stdin);
    printf("Average word length: %.2lf\n", compute_average_word_length(sentence));
    return 0;
}
double compute_average_word_length(const char *sentence)
{
    double x = 0.0, y = 1.0;
    while (*sentence != '\n')
    {
        if (*sentence++ == ' ')
            y++;
        else
            x++;
    }  
    return x / y;
}