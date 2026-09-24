/* Write a program that formats product information entered by the user. A session with the
program should look like this:
Enter item number: 583
Enter unit price: 13.5
Enter purchase date (mm/dd/yyyy): 10/24/2010
Item		Unit			Purchase
			Price			Date
583			$ 13.50			10/24/2010
The item number and date should be left justified; the unit price should be right justified.
Allow dollar amounts up to $9999.99. Hint: Use tabs to line up the columns.*/

#include <stdio.h>

int main(void)
{
	typedef struct
	{
		int item;
		float price;
		int m;
		int d;
		int y;
	}	table;

	table t;
	printf("Enter item number: ");
	scanf("%d", &t.item);
	printf("Enter unit price: ");
	scanf("%f", &t.price);
	if (t.price > 9999.99 || t.price < -9999.99)
		t.price = 9999.99;
	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d / %d / %d", &t.m, &t.d, &t.y);
	printf("Item\t\t\tUnit\t\t\tPurchase\n\t\t\tPrice\t\t\tDate\n");
	printf("%d\t\t\t$ %.2f\t\t%d/%d/%d\n", t.item, t.price, t.m, t.d, t.y);
}
