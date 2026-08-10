/* Write a program that sorts a series of words entered by the user:
Enter word: foo
Enter word: bar
Enter word: baz
Enter word: quux
Enter word:
In sorted order: bar baz foo quux
Assume that each word is no more than 20 characters long. Stop reading when the user
enters an empty word (i.e., presses Enter without entering a word). Store each word in a
dynamically allocated string, using an array of pointers to keep track of the strings, as in the
remind2.c program (Section 17.2). After all words have been read, sort the array (using
any sorting technique) and then use a loop to print the words in sorted order. Hint: Use the
read_line function to read each word, as in remind2.c. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20

int comp(const void *a, const void *b);

int main(void)
{
    int i, len;
    char **str = malloc(1 * sizeof(char *));
    for (i = 0; ; i++)
    {
        str = realloc(str, (i + 1) * sizeof(char *));
        str[i] = malloc(WORD_LEN * sizeof(char));
        printf("Enter word: ");
        fgets(str[i], WORD_LEN, stdin);
        if (str[i][0] == '\n')
            break;
        len = strlen(str[i]);
        if (len > 0 && str[i][len - 1] == '\n')
            str[i][len - 1] = '\0';
    }
    free(str[i]);
    str[i] = NULL;
    qsort(str, i, sizeof(char *), comp);
    printf("In sorted order: ");
    for (i = 0; str[i] != NULL; i++)
    {
        printf("%s ", str[i]);
        free(str[i]);
    }
    free(str[i]);
    printf("\n");
    free(str);
    return 0;
}

int comp(const void *a, const void *b)
{
    return (strcmp(*(const char **)a, *(const char **)b));
}