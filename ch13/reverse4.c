/* Write a program named reverse.c that echoes its command-line arguments in reverse
order. Running the program by typing
reverse void and null
should produce the following output:
null and void */
#include <stdio.h>

int main(int argc, char *argv[])
{
    while (argc-- > 1)
        printf("%s ", argv[argc]);
    putchar('\n');
    return 0;
}