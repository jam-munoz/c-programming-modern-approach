#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

int main(void)
{
	struct node *first = NULL;
}

struct node push_node(struct node *list, int data)
{
	struct node *push = malloc(sizeof(struct node));

	push->value = data;
	(*push)->next = list;
}
