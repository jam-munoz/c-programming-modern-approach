#include <stdio.h>

int main ()
{
    float price;
    printf ("Enter an ammount: ");
    scanf ("%f", &price);
    float tax = price / 20.0f;
    printf ("With tax added: %.2f\n", (price + tax));
    return 0;
}