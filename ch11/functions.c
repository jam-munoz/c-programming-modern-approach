/* The following function supposedly computes the sum and average of the numbers in the
array a, which has length n. avg and sum point to variables that the function should mod-
ify. Unfortunately, the function contains several errors; find and correct them. */
void avg_sum(double a[], int n, double *avg, double *sum)
{
    int i;
    *sum = 0.0;
    for (i = 0; i < n; i++)
        *sum += a[i];
    *avg = *sum / n;
}

/*Write the following function:
void swap(int *p, int *q);
When passed the addresses of two variables, swap should exchange the values of the variables:
swap(&i, &j);
 /* exchanges values of i and j */ 
void swap(int *p, int *q)
{
    int i;
    i = *p;
    *p = *q;
    *q = i;
}

/* Write the following function:
void split_time(long total_sec, int *hr, int *min, int *sec);
total_sec is a time represented as the number of seconds since midnight. hr, min, and
sec are pointers to variables in which the function will store the equivalent time in hours
(0–23), minutes (0–59), and seconds (0–59), respectively.*/
void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *hr = total_sec / 3600;
    *min = (total_sec % 3600) / 60;
    *sec = (total_sec % 3600) % 60;
}

/* Write the following function:
void find_two_largest(int a[], int n, int *largest, int *second_largest); 
When passed an array a of length n, the function will search a for its largest and second-
largest elements, storing them in the variables pointed to by largest and second_largest, respectively.*/
void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    int i, big = 0, biggest = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] > biggest)
            biggest = a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] > big && a[i] < biggest)
            big = a[i];
    }
    *largest = biggest;
    *second_largest = big;
}

/* Write the following function:
void split_date(int day_of_year, int year, int *month, int *day);
day_of_year is an integer between 1 and 366, specifying a particular day within the year
designated by year. month and day point to variables in which the function will store the
equivalent month (1–12) and day within that month (1–31). */
void split_date(int day_of_year, int year, int *month, int *day)
{
    bool isleap = false;
    if (day_of_year < 32)
    {
        *month = 1;
        *day = day_of_year; return;
    }
    if ((((year % 4) == 0) && ((year % 100) != 0)) || (((year % 100) == 0) && ((year % 400) == 0)))
        isleap = true;

    if ((day_of_year < 60) || (isleap = true) && (day_of_year = 60))
    {
        *month = 2;
        *day = day_of_year - 31; return;
    }

    if (isleap = true)
        day_of_year--;

    if ((day_of_year < 91))
    {
        *month = 3;
        *day = day_of_year - 59; return;
    }
    
    /*ETC*/
}

/* Write the following function:
int *find_largest(int a[], int n);
When passed an array a of length n, the function will return a pointer to the array’s largest element. */
int *find_largest(int a[], int n)
{
    int big = 0, *p;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > big)
        {
            big = a[i];
            p = &a[i];
        }
    }
    return p;
}