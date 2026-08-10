/* Having to check the return value of malloc (or any other memory allocation function)
 e ach time we call it can be an annoyance. Write a function named my_malloc that serves
 as a “wrapper” for malloc. When we call my_malloc and ask it to allocate n bytes, it in
 turn calls malloc, tests to make sure that malloc doesn’t return a null pointer, and then
 returns the pointer from malloc. Have my_malloc print an error message and terminate
 the program if malloc returns a null pointer. */

void *my_malloc(int size)
{
	void *out = malloc(size);
	{
		if (out == NULL)
		{
				printf("ERROR - MALLOC UNSUCCESFUL\n");
				exit(EXIT_FAILURE);
		}
		return out;
}

/* Write a function named duplicate that uses dynamic storage allocation to create a copy
 o f a string. For example*, the call
 p = duplicate(str);
 would allocate space for a string of the same length as str, copy the contents of str into
 the new string, and return a pointer to it. Have duplicate return a null pointer if the
 memory allocation fails.*/

char *duplicate(char *str)
{
	char *p = str;
	char *out;
	while (*p != '\0')
		p++;
	int len = p - str;
	out = malloc((len + 1) * sizeof(char));
	if (out == NULL)
		return NULL;

	for(p = out; *str != '\0'; p++, str++)
		*p = *str;
	*p = '\0';

	return out;
}

/* Write the following function:
 int *create_array(int n, *int initial_value);
 The function should return a pointer to a dynamically allocated int array with n members,
 each of which is initialized to initial_value. The return value should be NULL if the
 array can’t be allocated. */

int *create_array(int n, int initial_value)
{
	int *arr = malloc(n * sizeof(int));
	if (arr == NULL)
		return NULL;
	int *p = arr;

	for (int *end = p + n; p < end; p++)
		*p = initial_value;

	return arr;
}

/*Suppose that the following declarations are in effect:
 struct point { int x, y; };
 struct rectangle { struct point upper_left, lower_right; };
 struct rectangle *p;
 Assume that we want p to point to a rectangle structure whose upper left corner is at
 (10, 25) and whose lower right corner is at (20, 15). Write a series of statements that allocate
 such a structure and initialize it as indicated.*/
p->upper_left = { 10, 25 };
p->lower_right = { 20, 15 };

/* Suppose that f and p are declared as follows:
struct {
	union {
		char a, b;
		int c;
	} d;
	int e[5];
} f, *p = &f;
Which of the following statements are legal?
(a) p->b = ' ';
(b) p->e[3] = 10;
(c) (*p).d.a = '*';
(d) p->d->c = 20;*/
b, c

/*The following loop is supposed to delete all nodes from a linked list and release the memory
 that they occupy. Unfortunately, the loop is incorrect. Explain what’s wrong with it and show how to fix the bug.
 for (p = first; p != NULL; p = p->next)
	 free(p);*/
for (p = first; p != NULL; )
{
	remove = p;
	p = p->next;
	free(remove);
}

/* Write the following function:
 int count_occurrences(struct node *list, int n);
 The list parameter points to a linked list; the function should return the number of times
 that n appears in this list. Assume that the node structure is the one defined in Section 17.5.*/
int count_occurrences(struct node *list, int n)
{
	int count = 0;
	for (; *list != NULL; list = list->next)
		if (list->value == n)
			count++;

	return count;
}

/*Write the following function:
 struct node *find_last(struct node *list, int n);
 The list parameter points to a linked list. The function should return a pointer to the last
 node that contains n; it should return NULL if n doesn’t appear in the list. Assume that the
 node structure is the one defined in Section 17.5.*/
struct node *find_last(struct node *list, int n)
{
	struct node *find;

	for (; *list != NULL; list = list->next)
		if (list->value == n)
			find = list;

	return find;
}

/*Let a be an array of 100 integers. Write a call of qsort that sorts only the last 50 elements
 in a. (You don’t need to write the comparison function).*/
#include <stdlib.h>
 qsort(&str[49], 50, sizeof(int), compare_ints);
