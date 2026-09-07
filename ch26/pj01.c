/* (a) Write a program that calls the rand function 1000 times, printing the low-order bit of
each value it returns (0 if the return value is even, 1 if it’s odd). Do you see any patterns?
(Often, the last few bits of rand’s return value aren’t especially random.)
(b) How can we improve the randomness of rand for generating numbers within a small range?*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*int main(void)
{
	for (int i = 0; i < 999; i++)
	{
		printf("%d, ", rand() & 1);
	}
	printf("%d.\n", rand() & 1);
}*/

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 999; i++)
	{
		printf("%d, ", rand() / (RAND_MAX / 10 + 1));
	}
	printf("%d.\n", rand() / (RAND_MAX / 10 + 1));
}
