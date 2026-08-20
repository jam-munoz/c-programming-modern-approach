#include "counter.h"

static int count = 0;

void increment_count(void)
{
    count++;
}

void read_int(void)
{
    printf("%d\n", count);
}
