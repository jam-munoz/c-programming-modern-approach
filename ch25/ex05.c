/* Repeat Exercise 4, this time using the UTF-8 multibyte encoding. For example, the phrase
déjà vu could be represented by the string "d\xc3\xa9j\xc3\xa0 vu".*/
#include <stdio.h>

int main(void)
{
	printf("C\xc3\xb4te d'Azur\n");
	printf("cr\xc3\xa8me br\xc3\xbbl\xc3\xa9" "e\n");
	printf("cr\xc3\xa8me fra\xc3\xae" "che\n");
	printf("Fahrvergn\xc3\xbcn\n");
	printf("t\xc3\xaate-\xc3\xa0-t\xc3\xaate\n");
}
