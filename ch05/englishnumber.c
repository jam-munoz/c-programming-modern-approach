#include <stdio.h>

int main(void)
{
/*Write a program that asks the user for a two-digit number, then prints the English word for the number:
Enter a two-digit number: 45
You entered the number forty-five.
    Hint: Break the number into two digits. Use one switch statement to print the word for the
first digit (“twenty,” “thirty,” and so forth). Use a second switch statement to print the
word for the second digit. Don’t forget that the numbers between 11 and 19 require special treatment.*/
int number;
printf ("Enter a two-digit number: ");
scanf ("%d", &number);
if (number < 10 || number > 99)
    {
        printf ("Invalid number.\n");
        return 1;
    }

if (number >= 10 && number < 20)
    {
    switch (number)
    {
        case 19: printf ("Nineteen.\n"); break;
        case 18: printf ("Eighteen.\n"); break;
        case 17: printf ("Seventeen.\n"); break;
        case 16: printf ("Sixteen.\n"); break;
        case 15: printf ("Fifteen.\n"); break;
        case 14: printf ("Fourteen.\n"); break;
        case 13: printf ("Thirteen.\n"); break;
        case 12: printf ("Twelve.\n"); break;
        case 11: printf ("Eleven.\n"); break;
        case 10: printf ("Ten.\n"); break;
    }
    return 0;
    }

int digit1 = (number % 10);
int digit10 = (number / 10);

switch (digit10)
{
    case 9: printf ("Ninety"); break;
    case 8: printf ("Eighty"); break;
    case 7: printf ("Seventy"); break;
    case 6: printf ("Sixty"); break;
    case 5: printf ("Fifty"); break;
    case 4: printf ("Fourty"); break;
    case 3: printf ("Thirty"); break;
    case 2: printf ("Twenty"); break;
}

switch (digit1)
{
    case 9: printf ("-nine.\n"); break;
    case 8: printf ("-eight.\n"); break;
    case 7: printf ("-seven.\n"); break;
    case 6: printf ("-six.\n"); break;
    case 5: printf ("-five.\n"); break;
    case 4: printf ("-four.\n"); break;
    case 3: printf ("-three.\n"); break;
    case 2: printf ("-two.\n"); break;
    case 1: printf ("-one.\n"); break;
    case 0: printf (".\n"); break;
}
return 0;
}