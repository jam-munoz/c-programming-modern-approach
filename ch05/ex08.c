/* The following if statement is unnecessarily complicated. Simplify it as much as possible.
(Hint: The entire statement can be replaced by a single assignment.)
if (age >= 13)
if (age <= 19)
teenager = true;
else
teenager = false;
else if (age < 13)
teenager = false;*/

#include <stdio.h>

int main(void)
{
	int age;
	bool teenager;
	printf("Enter the age: ");
	scanf(" %d", &age);

	teenager = age >=13 && age <= 19 ? true : false;

	printf("teenager = ");
	printf("%s\n", teenager ? "true" : "false");
}
