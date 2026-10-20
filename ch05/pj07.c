/* Write a program that finds the largest and smallest of four integers entered by the user:
Enter four integers: 21 43 10 35
Largest: 43
Smallest: 10
Use as few if statements as possible. Hint: Four if statements are sufficient.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 4

static int comp(const void *a, const void *b);

int main(void)
{
	int arr[MAX];

	printf("Enter %d integers: ", MAX);
	for (int i = 0; i < MAX; i++)
	{
		if (scanf(" %d", &arr[i]) != 1)
		{
			printf("Wrong format.\n");
			exit(EXIT_FAILURE);
		}
	}
	qsort(arr, MAX, sizeof(int), comp);
	printf("Largest: %d\nSmallest: %d\n", arr[MAX - 1], arr[0]);
}

static int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
