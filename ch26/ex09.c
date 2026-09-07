/* Write a function that returns a random double value d in the range 0.0 ≤ d < 1.0.*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double random_double_value(void)
{
	srand(time(NULL));

	return (double)rand() / (RAND_MAX + 1.0);
}

int main(void)
{
	double	d = random_double_value();

	printf("%lf\n", d);
}
