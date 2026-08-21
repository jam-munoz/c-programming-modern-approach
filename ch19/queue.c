#define MAX_SIZE 20
#include "queue.h"

static int arr[MAX_SIZE] = { 0 };
static int len = 0;

void push_queue(int data)
{
    if (len >= MAX_SIZE - 1)
    {
        printf("Error, max size reached.\n");
        return;
    }
    arr[len] = data;
    len++;
    return;
}

void remove_front(void)
{
    if (len < 1)
        return;

    len--;
    for (int i = 0; i < len; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[len] = 0;
}

void remove_back(void)
{
    if (len < 1)
        return;
    len--;
    arr[len] = 0;
}

bool is_empty_queue(void)
{
    return !len;
}
