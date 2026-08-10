/*Calculators, watches, and other electronic devices often rely on seven-segment displays for
numerical output. To form a digit, such devices “turn on” some of the seven segments while
leaving others “off”
Suppose that we want to set up an array that remembers which segments should be “on” for
each digit. 
Here’s what the array might look like, with each row representing one digit:
const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, …};
I’ve given you the first row of the initializer; fill in the rest.*/

#include <stdio.h>

int main(void)
{
    const int segments[10][7]= {{1, 1, 1, 1, 1, 1}, 
                                {0, 1, 1}
                                {1, 1, 0, 1, 1, 0, 1}
                                {1, 1, 1, 1, [6] = 1}
                                {0, 1, 1, [5] = 1, 1}
                                {1, 0, 1, 1, 0, 1, 1}
                                {1, 0, 1, 1, 1, 1, 1}
                                {1, 1, 1}
                                {1, 1, 1, 1, 1, 1, 1}
                                {1, 1, 1, 1, 0, 1, 1}};
}