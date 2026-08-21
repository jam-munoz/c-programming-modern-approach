#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>

void push_queue(int data);
void remove_front(void);
void remove_back(void);
bool is_empty_queue(void);

#endif
