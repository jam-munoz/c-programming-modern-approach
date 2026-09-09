/* Write a program that tests whether your compiler’s "" (native) locale is the same as its "C" locale.*/
#include <locale.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *native = setlocale(LC_ALL, "");
	if (native == NULL)
	{
		printf("Failed to set native locale.\n");
		return 1;
	}
	
	if (strcmp("C", native) == 0)
		printf("Native locale is the same as C locale.\n");
	else
		printf("Native locale is different from C locale.\n");
}
