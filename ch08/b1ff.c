/* The prototypical Internet newbie is a fellow named B1FF, who has a unique way of writing
messages. Here’s a typical B1FF communiqué:
H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
Write a “B1FF filter” that reads a message entered by the user and translates it into B1FF-speak:
Enter message: Hey dude, C is rilly cool
In B1FF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
Your program should convert the message to upper-case letters, substitute digits for certain
letters (A→4, B→8, E→3, I→1, O→0, S→5), and then append 10 or so exclamation marks.
Hint: Store the original message in an array of characters, then go back through the array,
translating and printing characters one by one. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{

    char c; 
    char message[100] = {0};
    int i = 0;

    printf("Enter message: ");
    while((c = getchar()) != '\n' && i < 100)
    {
        message[i] = c;
        i++;
    }
    message[i] = '\0';
    int len = strlen(message);
    printf ("In B1FF-speak: ");
    for (i = 0; i < len; i++)
    switch (toupper(message[i]))
    {
        case 'A': printf("4"); break;
        case 'B': printf("8"); break;
        case 'E': printf("3"); break;
        case 'I': printf("1"); break;
        case 'O': printf("0"); break;
        case 'S': printf("5"); break;
        default: putchar(toupper(message[i])); break;
    }
    printf ("!!!!!!!!!!\n");
    return 0;
}