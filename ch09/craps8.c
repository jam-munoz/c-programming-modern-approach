/* Write a program that simulates the game of craps, which is played with two dice. On the
first roll, the player wins if the sum of the dice is 7 or 11. The player loses if the sum is 2, 3,
or 12. Any other roll is called the “point” and the game continues. On each subsequent roll,
the player wins if he or she rolls the point again. The player loses by rolling 7. Any other roll
is ignored and the game continues. At the end of each game, the program will ask the user
whether or not to play again. When the user enters a response other than y or Y, the program
will display the number of wins and losses and then terminate.
Write your program as three functions: main, roll_dice, and play_game. Here are
the prototypes for the latter two functions:
int roll_dice(void);
bool play_game(void);
roll_dice should generate two random numbers, each between 1 and 6, and return their
sum. play_game should play one craps game (calling roll_dice to determine the out-
come of each dice roll); it will return true if the player wins and false if the player loses.
play_game is also responsible for displaying messages showing the results of the player’s
dice rolls. main will call play_game repeatedly, keeping track of the number of wins and
losses and displaying the “you win” and “you lose” messages. Hint: Use the rand function
to generate random numbers. See the deal.c program in Section 8.2 for an example of
how to call rand and the related srand function. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void) 
{
    srand((unsigned) time(NULL));
    char c;
    int win = 0, lose = 0;
    do
    {
        if (play_game() == true)
        {
            printf("You win!\nPlay again? ");
            win++;
        }
        else
        {
            printf("You lose!\nPlay again? ");
            lose++;
        }
        scanf(" %c", &c);
    } while ((c == 'y') || (c == 'Y'));
    printf("Wins: %d\nLosses: %d\n", win, lose);
}

int roll_dice(void)
{
    return ((rand() % 6) + 1) + ((rand() % 6) + 1);
}

bool play_game(void)
{
    int i = roll_dice();
    printf("You rolled: %d\n", i);
    switch (i)
    {
        case 7: case 11: return true; break;
        case 2: case 3: case 12: return false; break;
        default: printf("Your point is %d\n", i); break;
    }
    int j;
    while ((j = roll_dice()))
    {
        printf("You rolled: %d\n", j);
        if (i == j)
            return true;
        else if (j == 7)
            return false;
    }
}