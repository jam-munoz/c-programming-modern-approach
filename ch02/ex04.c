/* Write a program that declares several int and float variables—without initializing
them—and then prints their values. Is there any pattern to the values? (Usually there isn’t.)*/

#include <stdio.h>

int main(void)
{
	int a, b, c;
	float x, y, z;

	printf("a: %d, b: %d, c: %d\n", a, b, c);
	printf("x: %f, y: %f, z: %f\n", x, y, z);
}
