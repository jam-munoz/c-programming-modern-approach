/* Give a C string literal that represents each of the following phrases. Assume that the charac-
ters à, è, é, ê, î, ô, û, and ü are represented by single-byte Latin-1 characters. (You’ll need to
look up the Latin-1 code points for these characters.) For example, the phrase déjà vu could
be represented by the string "d\xe9j\xe0 vu".
(a) Côte d'Azur
(b) crème brûlée
(c) crème fraîche
(d) Fahrvergnügen
(e) tête-à-tête*/
#include <stdio.h>

int main(void)
{
	printf("C\xf4te d'Azur\n");
	printf("cr\xe8me br\xfbl\xe9" "e\n");
	printf("cr\xe8me fra\xee" "che\n");
	printf("Fahrvergn\xfcn\n");
	printf("t\xeate-\xe0-t\xeate\n");
}
