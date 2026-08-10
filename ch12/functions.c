#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/* Write the following function:
bool search(const int a[], int n, int key);
a is an array to be searched, n is the number of elements in the array, and key is the search
key. search should return true if key matches some element of a, and false if it
doesn’t. Use pointer arithmetic—not subscripting—to visit array elements.*/
bool search(int a[], int n, int key)
{
    int *p = &a[0];
    while (p++ < &a[n])
    {
        if (key == *p)
            return true;
    }
    return false;
}

/* Write the following function:
double inner_product(const double *a, const double *b, int n);
a and b both point to arrays of length n. The function should return a[0] * b[0] + a[1] * b[1] + … + a[n-1] * b[n-1]. 
Use pointer arithmetic—not subscripting—to visit array elements.*/
double inner_product(const double *a, const double *b, int n)
{
    int i = 0;
    double j = 0.0;
    while (i++ < n)
    {
       j += (*(a+i)) * (*(b+i));
    }
    return j;
}

/* Write the following function:
void find_two_largest(const int *a, int n, int *largest, int *second_largest);
a points to an array of length n. The function searches the array for its largest and second-
largest elements, storing them in the variables pointed to by largest and
second_largest, respectively. Use pointer arithmetic—not subscripting—to visit array elements. */
void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
    int big = 0, biggest = 0, i = 0;
    while (i++ < n)
    {
        if (*(a+i) > biggest)
            biggest = *(a+i);
    }
    i = 0;
    while (i++ < n)
    {
        if (*(a+i) > big && *(a+i) < biggest)
            big = *(a+i);
    }
    *largest = biggest;
    *second_largest = big;
}

int main(void)
{
    char s[] = "las papas s.a.";
    int string[strlen(s)];
    int key = 'p';
    memcpy(string, s, sizeof(int));
    bool papa = search(string, strlen(s), key);
    if (papa)
    {
        printf("anda\n");
    }
    else printf("no anda\n");
}