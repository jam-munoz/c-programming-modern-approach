#include <stdio.h>

int main ()
{
/*Write a program that asks the user to enter the numbers from 1 to 16 (in any order) and then
displays the numbers in a 4 by 4 arrangement, followed by the sums of the rows, columns,
and diagonals:*/
    const int SIXTEEN = 16;
    int numbers[SIXTEEN];
    printf ("Enter the numbers from 1 to 16 in any order: \n");
    for (int i=0; i < SIXTEEN; i++)
        {
        scanf ("%d", &numbers[i]);
        }

// display the numbers in a 4 by 4 arrangement
    printf ("\n%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n", 
    numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8], 
    numbers[9], numbers[10], numbers[11], numbers[12], numbers[13], numbers[14], numbers[15]);

// sum of rows, columns, and diagonals
    printf ("\nRow sums: %d, %d, %d, %d\n", (numbers[0] + numbers[1] + numbers[2] + numbers[3]), (numbers[4] + numbers[5] + numbers[6] + numbers[7]), 
    (numbers[8] + numbers[9] + numbers[10] + numbers[11]), (numbers[12] + numbers[13] + numbers[14] + numbers[15]));

    printf ("Column sums: %d, %d, %d, %d\n", (numbers[0] + numbers[4] + numbers[8] + numbers[12]), (numbers[1] + numbers[5] + numbers[9] + numbers[13]), 
    (numbers[2] + numbers[6] + numbers[10] + numbers[14]), (numbers[3] + numbers[7] + numbers[11] + numbers[15]));

    printf ("Diagonal sums: %d, %d\n", (numbers[0] + numbers[5] + numbers[10] + numbers[15]), (numbers[3] + numbers[6] + numbers[9] + numbers[12]));

    return 0;
}