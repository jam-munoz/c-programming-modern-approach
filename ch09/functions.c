#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

/* Write a function check(x, y, n) that returns 1 if both x and y fall between 0 and n – 1,
inclusive. The function should return 0 otherwise. Assume that x, y, and n are all of type int. */
int check(int x, int y, int n)
{
    if (x > 0 && x < (n - 1))
    {
        if (y > 0 && y < (n - 1))
        {
            return 1;
        }
    }
    else return 0;
}

/* Write a function gcd(m, n) that calculates the greatest common divisor of the integers m
and n. (Programming Project 2 in Chapter 6 describes Euclid’s algorithm for computing the GCD.) */
int gcd(int m, int n)
{
    int k;
    while (n > 0)
    {
        k = m % n;
        m = n;
        n = k;
    }
    return m;
}

/* Write a function day_of_year(month, day, year) that returns the day of the year
(an integer between 1 and 366) specified by the three arguments. */
int day_of_year(int month, int day, int year)
{
    const int JAN = 31, FEB = 28, MAR = 31, APR = 30, MAY = 31, JUN = 30, JUL = 31, AUG = 31, SEP = 30, OCT = 31, NOV = 30;
    bool isleap;
    if (month == 1)
        return day;
    else if (month == 2)
        return (JAN + day);
    //leap year?
    else if ((year % 4) == 0)
    {
        if ((year % 100) == 0)
        {
            if ((year % 400) == 0)
                isleap = true;
            else isleap = false; 
        }
        else isleap = true;
    }
    else isleap = false; 

    switch(month)
    {
        case 3: day = (JAN + FEB + day); break;
        case 4: day = (JAN + FEB + MAR + day); break; 
        case 5: day = (JAN + FEB + MAR + APR + day); break; 
        case 6: day = (JAN + FEB + MAR + APR + MAY + day); break; 
        case 7: day = (JAN + FEB + MAR + APR + MAY + JUN + day); break; 
        case 8: day = (JAN + FEB + MAR + APR + MAY + JUN + JUL + day); break; 
        case 9: day = (JAN + FEB + MAR + APR + MAY + JUN + JUL + AUG + day); break; 
        case 10: day = (JAN + FEB + MAR + APR + MAY + JUN + JUL + AUG + SEP + day); break; 
        case 11: day = (JAN + FEB + MAR + APR + MAY + JUN + JUL + AUG + SEP + OCT + day); break; 
        case 12: day = (JAN + FEB + MAR + APR + MAY + JUN + JUL + AUG + SEP + OCT + NOV + day); break; 
        default: return 0; break;
    }
    if (isleap)
        return day + 1;
    else return day;
}

/* Write a function num_digits(n) that returns the number of digits in n (a positive inte-
ger). Hint: To determine the number of digits in a number n, divide it by 10 repeatedly.
When n reaches 0, the number of divisions indicates how many digits n originally had. */
int num_digits(int n)
{
    int digits;
    for (digits = 0; n > 0; digits++)
        n = n / 10;
    return digits;
}

/* Write a function digit(n, k) that returns the k digit (from the right) in n (a positive integer). 
For example, digit(829, 1) returns 9, digit(829, 2) returns 2, and digit(829, 3) returns 8. 
If k is greater than the number of digits in n, have the function return 0. */
int digit(int n, int k)
{
    int digits;
    for (int numcopy = n; numcopy > 0; digits++)
            numcopy = numcopy / 10;
    if (k > digits)
        return 0;

    int reversal[digits];
    for (int i = 0; i <= (digits - 1); i++)
        {
            reversal[i] = n % 10;
            n = n / 10;
        }
    return reversal[k-1];
}

/* Write functions that return the following values. (Assume that a and n are parameters,
where a is an array of int values and n is the length of the array.)
(a) The largest element in a.
(b) The average of all elements in a.
(c) The number of positive elements in a. */
int largest_element(int a[], int n)
{
    int largest = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > largest)
            largest = a[i];
        return largest;
    }
}
int average_elements(int a[], int n)
{
    float average;
    for (int i = 0; i < n; i++)
    {
        average += a[i];
    }
    average /= n;
    return average;
}
int number_positive(int a[], int n)
{
    int positive = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            positive++;
        return positive;
    }
}

/* Write the following function:
float compute_GPA(char grades[], int n);
The grades array will contain letter grades (A, B, C, D, or F, either upper-case or lower-
case); n is the length of the array. The function should return the average of the grades
(assume that A = 4, B = 3, C = 2, D = 1, and F = 0). */
float compute_GPA(char grades[], int n)
{
    float average = 0.0f;
    for (int i = 0; i < n; i++)
    {
        switch(toupper(grades[i]))
        {
            case 'A': average += 4; break;
            case 'B': average += 3; break;
            case 'C': average += 2; break;
            case 'D': average += 1; break;
            default: break;
        }
    }
    average /= n;
    return average;
}

/* Write the following function:
double inner_product(double a[], double b[], int n);
The function should return a[0] * b[0] + a[1] * b[1] + … + a[n-1] * b[n-1].*/
double inner_product(double a[], double b[], int n)
{
    double product = 0.0;
    for (int i = 0; i < n; i++)
        product += (a[i] * b[i]);
    return product;
}

/* Write the following function, which evaluates a chess position:
int evaluate_position(char board[8][8]);
board represents a configuration of pieces on a chessboard, where the letters K, Q, R, B, N,
P represent White pieces, and the letters k, q, r, b, n, and p represent Black pieces.
evaluate_position should sum the values of the White pieces (Q = 9, R = 5, B = 3,
N = 3, P = 1). It should also sum the values of the Black pieces (done in a similar way). The
function will return the difference between the two numbers. This value will be positive if
White has an advantage in material and negative if Black has an advantage. */
int evaluate_position(char board[8][8])
{
    int i, j, white = 0, black = 0;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            switch (board[i][j])
            {
                case 'Q': white += 9; break;
                case 'R': white += 5; break;
                case 'B': white += 3; break;
                case 'N': white += 3; break;
                case 'P': white += 1; break;
                case 'q': black += 9; break;
                case 'r': black += 5; break;
                case 'b': black += 3; break;
                case 'n': black += 3; break;
                case 'p': black += 1; break;
            }
        }
    }
    return (white - black);
}

/* The following function is supposed to return true if any element of the array a has the
value 0 and false if all elements are nonzero. Sadly, it contains an error. Find the error and
show how to fix it: */
bool has_zero(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == 0)
            return true;
    }
        return false;
}

/* The following (rather confusing) function finds the median of three numbers. Rewrite the
function so that it has just one return statement. */
double median(double x, double y, double z)
{
    if ((x <= y && y <= z) || (z <= y && y <= x)) return y;
    if ((x <= z && z <= y) || (y <= z && z <= x)) return z;
    if ((y <= x && x <= z) || (z <= x && x <= y)) return x; 
}

/* Condense the fact function in the same way we condensed power.*/
int fact(int n)
{
    return n <= 1 ? 1 : n * fact(n - 1);
}
/* Rewrite the fact function so that it’s no longer recursive.*/
int fact2(int n)
{
    int k = 1;
    while (n >= 1)
    {
        k *= n * (n - 1);
        n--;
    }
    return k;
}

/* Write a recursive version of the gcd function (see Exercise 3). Here’s the strategy to use for
computing gcd(m, n): If n is 0, return m. Otherwise, call gcd recursively, passing n as
the first argument and m % n as the second. */
int gcd2(int m, int n)
{
    if (n = 0)
        return m;
    else 
        return gcd(n, (m % n));
}

void pb(int n)
{
    if (n != 0) 
    {
        pb(n / 2);
        putchar('0' + n % 2);
    }
}
///////////////////////////////////
int main(void)
{
    pb(32);
    putchar('\n');
    return 0;
}