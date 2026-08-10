/*Write a program that evaluates an expression:
Enter an expression: 1+2.5*3
Value of expression: 10.5
The operands in the expression are floating-point numbers; the operators are +, -, *, and /.
The expression is evaluated from left to right (no operator takes precedence over any other
operator).*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
float x, y, z, value;
char op1, op2;
printf ("Enter an expression: ");
scanf ("%f %c %f %c %f", &x, &op1, &y, &op2, &z);

switch (op1)
    {
        case '+': value = x + y; break;
        case '-': value = x - y; break;
        case '*': value = x * y; break;
        case '/': value = x / y; break;
    }

switch (op2)
    {
        case '+': value = value + z; break;
        case '-': value = value - z; break;
        case '*': value = value * z; break;
        case '/': value = value / z; break;
    }
    
printf ("Value of expression: %.2f.\n", value);
return 0;
}