/* Write a program that uses the clock function to measure how long it takes qsort to sort
an array of 1000 integers that are originally in reverse order. Run the program for arrays of
10000 and 100000 integers as well.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 100000

int comp(const void *a, const void *b);

int main(void)
{
	clock_t start_clock;
	int arr[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; i++)
	{
		arr[i] =  ARR_SIZE - i;
	}

	start_clock = clock();
	qsort(arr, ARR_SIZE, sizeof(int), comp);

	printf("Processor time used: %g sec.\n", (clock() - start_clock) / (double) CLOCKS_PER_SEC);
}

int comp(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}
