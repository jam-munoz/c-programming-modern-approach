/* Write a program that declares the s structure (see Section 21.4) and prints the sizes and
offsets of the a, b, and c members. (Use sizeof to find sizes; use offsetof to find offsets.)
Have the program print the size of the entire structure as well. From this information, determine
whether or not the structure has any holes. If it does, describe the location and size of each.*/
#include <stdio.h>
#include <stddef.h>

struct s
{
    char a;
    int b[2];
    float c;
};

int main(void)
{
    struct s test;
    printf("sizeof a: %d, b: %d, c: %d\n", sizeof(test.a), sizeof(test.b), sizeof(test.c));
    printf("offsetof a: %d, b: %d, c: %d\n", offsetof(struct s, a), offsetof(struct s, b), offsetof(struct s, c));
    printf("sizeof struct: %d\n", sizeof(test));
}
