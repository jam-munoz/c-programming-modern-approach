/* Modify Programming Project 5 from Chapter 5 so that it uses a function to compute the amount of 
income tax. When passed an amount of taxable income, the function will return the tax due. */

#include <stdio.h>
float tax_due(float n);

int main(void) {

    float income;

    printf("Enter taxable income: ");
    scanf("%f", &income);

    printf("Tax due: $%.2f\n", tax_due(income));

    return 0;
}

float tax_due(float n)
{
    if (n <= 750.00f)
        return .01f * n;
    else if (n <= 2250.00f)
        return 7.50f + (.02f * (n - 750.00f));
    else if (n <= 3750.00f)
        return 37.50f + (.03f * (n - 2250.00f));
    else if (n <= 5250.00f)
        return 82.50f + (.04f * (n - 3750.00f));
    else if (n <= 7000)
        return 142.50f + (.05f * (n - 5250.00f));
    else
        return 230.00f + (.06f * (n - 7000.00f));
}