/* Write a program that asks the user to enter a series of integers (which it stores in an array),
then sorts the integers by calling the function selection_sort. When given an array
with n elements, selection_sort must do the following:
1. Search the array to find the largest element, then move it to the last position in the array.
2. Call itself recursively to sort the first n – 1 elements of the array. */

#include <stdio.h>

void selection_sort(int elements[], int n);

int main(void)
{
    int i = 0, numbers[5];
    printf("Enter a series of integers: ");
    while ((getchar()) != '\n')
        scanf(" %d", &numbers[i++]);
    //printf("%d %d\n \n", numbers[0], numbers[3]);
    selection_sort(numbers, 5);
    for (int i = 0; i < 5; i++) 
        printf("%d ", numbers[i]);
    putchar('\n');
}

void selection_sort(int elements[], int n)
{
    int a, b, i, j;
    if (n <= 0)
        return; 
    for (i = 0, a = 0; i < n; i++)
        if (elements[i] > a)
        {
            a = elements[i];
            j = i;
        }
    b = elements[i];
    elements [i] = a;
    elements [j] = b;
}