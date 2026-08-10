/* Write a program that reads a 5 × 5 array of integers and then prints the row sums and the
column sums:
Enter row 1: 8 3 9 0 10
Enter row 2: 3 5 17 1 1
Enter row 3: 2 8 6 23 1
Enter row 4: 15 7 3 2 9
Enter row 5: 6 14 2 6 0
Row totals: 30 27 40 36 28
Column totals: 34 37 37 32 21 */

#include <stdio.h>

int main(void)
{
    const int K = 5;
    int i, j, row = 0, papas[K][K];
    for (i = 0; i < K; i++)
    {
        printf ("Enter row %d: ", (i + 1));
        for (j = 0; j < K; j++)
            scanf ("%d", &papas[i][j]); 
    }
    printf ("Row totals: ");
    for (i = 0; i < K; i++)
    {
        for (j = 0, row = 0; j < K; j++)
            row += papas[i][j];
        printf ("%d ", row);
    }
    printf ("\n");
    printf ("Column totals: ");
    for (i = 0; i < K; i++)
    {
        for (j = 0, row = 0; j < K; j++)
            row += papas[j][i];
        printf ("%d ", row);
    }
    printf ("\n");
    return 0;
}