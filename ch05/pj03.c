/*Modify the broker.c program of Section 5.2 by making both of the following changes:
(a) Ask the user to enter the number of shares and the price per share, instead of the value
of the trade.
(b) Add statements that compute the commission charged by a rival broker ($33 plus 3¢ per
share for fewer than 2000 shares; $33 plus 2¢ per share for 2000 shares or more). Dis-
play the rival’s commission as well as the commission charged by the original broker.*/

/* broker.c (Chapter 5, page 81) */
/* Calculates a broker's commission */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int shares;
	float commission, rival, value;

	printf("Enter the number of shares: ");
	if (scanf("%d", &shares) != 1)
	{
		printf("Wrong format.\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter the price per share: ");
	if (scanf("%f", &value) != 1)
	{
		printf("Wrong format.\n");
		exit(EXIT_FAILURE);
	}

	value *= (float)shares;
	if (value < 2500.00f)
		commission = 30.00f + .017f * value;
	else if (value < 6250.00f)
		commission = 56.00f + .0066f * value;
	else if (value < 20000.00f)
		commission = 76.00f + .0034f * value;
	else if (value < 50000.00f)
		commission = 100.00f + .0022f * value;
	else if (value < 500000.00f)
		commission = 155.00f + .0011f * value;
	else
		commission = 255.00f + .0009f * value;

	if (commission < 39.00f)
		commission = 39.00f;

	if (shares < 2000)
		rival = 33.0f + .03f * (float)shares;
	else
		rival = 33.0f + .02f * (float)shares;

	printf("Commission: $%.2f\n", commission);
	printf("Rival: $%.2f\n", rival);

	return 0;
}
