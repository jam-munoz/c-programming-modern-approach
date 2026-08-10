/* Modify Programming Project 7 so that it prompts for five 
quiz grades for each of five students, then computes the 
total score and average score for each student, and the 
average score, high score, and low score for each quiz. 
4 5 6 5 9
8 8 5 4 3
6 7 6 5 7
8 9 3 4 7
8 8 5 2 5
*/

#include <stdio.h>

int main(void)
{
    const int K = 5;
    int i, j, row = 0, papas[K][K];
    for (i = 0; i < K; i++)
    {
        printf ("Enter grades for quiz %c: ", (i + 65));
        for (j = 0; j < K; j++)
            scanf ("%d", &papas[i][j]); 
    }
    printf ("Total score: \n");
    for (i = 0; i < K; i++)
    {
        for (j = 0, row = 0; j < K; j++)
            row += papas[i][j];
        printf ("Student %c: %d, average: %.1f\n", (i + 65), row, (row / 5.0f));
    }
    printf ("Average score: ");
    for (i = 0, row = 0; i < K; i++)
    {
        for (j = 0; j < K; j++)
            row += papas[i][j];
    }
    printf ("%.2f \n", (row / 25.0f));

    for (i = 0, row = 0; i < K; i++)
    {
        for (j = 0; j < K; j++)
            if (papas[i][j] > row)
               row = papas[i][j];
    }
    printf ("Highest score: %d\n", row);
    
    for (i = 0, row = 11; i < K; i++)
    {
        for (j = 0; j < K; j++)
            if (papas[i][j] < row)
               row = papas[i][j];
    }
    printf ("Lowest score: %d\n", row);    
    return 0;
}