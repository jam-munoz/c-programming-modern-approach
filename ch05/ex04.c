/*Write a single expression whose value is either –1, 0, or +1, depending on whether i is less
than, equal to, or greater than j, respectively.*/

#include <stdio.h>

int main(void)
{
	int i, j, greater;
	printf("Enter two numbers: ");
	scanf(" %d %d", &i, &j);

	greater = (i - j < 0 ? -1 : 1) * (i != j);

	printf("%d\n", greater);
}
