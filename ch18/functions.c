int call_count(void)
{
    static int count = 0;
    count++;
    return count;
}

int ft_toggle(void)
{
    static int toggle = 0;

    if (toggle == 0)
        toggle = 1;
    else
        toggle = 0;
    return toggle;
}

int ft_running_average(int n)
{
    static int calls = 0;
    static int sum = 0;

    calls++;
    sum += n;

    return sum / calls;
}

#include <stdio.h>
int main(void)
{
    int count;
    for (int i = 0; i < 5; i++)
        count = call_count();
    printf("%d\n", count);
}
