/* The power function of Section 9.6 can be made faster by having it calculate xn in a differ-
ent way. We first notice that if n is a power of 2, then xn can be computed by squaring. For
example, x⁴ is the square of x², so x⁴ can be computed using only two multiplications instead
of three. As it happens, this technique can be used even when n is not a power of 2. If n is
even, we use the formula x^n = (x^(n/2))². If n is odd, then x^n = x × x^(n–1) . Write a recursive func-
tion that computes xn. (The recursion ends when n = 0, in which case the function returns 1.)
To test your function, write a program that asks the user to enter values for x and n, calls
power to compute xn, and then displays the value returned by the function. */

#include <stdio.h>
int power(int x, int n);

int main(void)
{
    int x, n;
    printf("Enter values for x, n: ");
    scanf("%d %d", &x, &n);
    int value = power(x, n);
    printf ("%d\n", value);
    return 0;
}

int power(int x, int n)
{
if (n == 0)
    return 1;
else if (n % 2 == 0)
    return power(x, n / 2) * power(x, n / 2);
else
    return x * power(x, n - 1);
}