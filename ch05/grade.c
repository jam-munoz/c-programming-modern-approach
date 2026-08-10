#include <stdio.h>

int main(void)
{
/*Using the switch statement, write a program that converts a numerical grade into a letter grade:
Enter numerical grade: 84
Letter grade: B
Use the following grading scale: A = 90–100, B = 80–89, C = 70–79, D = 60–69, F = 0–59.
Print an error message if the grade is larger than 100 or less than 0. Hint: Break the grade
into two digits, then use a switch statement to test the ten’s digit.*/
int grade;
char *letter = "Letter grade: ";
printf ("Enter numerical grade: ");
scanf ("%d", &grade);
if (grade <= 0 || grade > 100)
{
    printf ("Invalid grade.\n");
    return 1;
}
else grade = (grade / 10);

switch (grade)
{
    case 10:
    case 9: printf ("%sA\n", letter); break;
    case 8: printf ("%sB\n", letter); break;
    case 7: printf ("%sC\n", letter); break;
    case 6: printf ("%sD\n", letter); break;
    case 5: case 4: case 3 : case 2: case 1:
    case 0: printf ("%sF\n", letter); break;
}
return 0;
}