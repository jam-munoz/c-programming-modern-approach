#include <stdio.h>
/* Write parameterized macros that compute the following values.
(a) The cube of x.
(b) The remainder when n is divided by 4.
(c) 1 if the product of x and y is less than 100, 0 otherwise.
Do your macros always work? If not, describe what arguments would make them fail.*/
#define CUBE(x) ((x)*(x)*(x))
#define REMAINDER(n) ((n)%4)
#define PRODUCT_LESS_100(x,y) (((x)*(y))<100?1:0)
/* Write a macro NELEMS(a) that computes the number of elements in a one-dimensional
array a. Hint: See the discussion of the sizeof operator in Section 8.1.*/
#define NELEMS(a) ((int) (sizeof(a)/sizeof(a[0])))

int main(void)
{
    printf("%d, %d, %d\n", CUBE(5), REMAINDER(16), PRODUCT_LESS_100(20, 4));
}

