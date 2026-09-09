/* Write a program that obtains the name of a locale from the command line and then displays
the values stored in the corresponding lconv structure. For example, if the locale is
"fi_FI" (Finland), the output of the program might look like this:
decimal_point = ","
thousands_sep = " "
grouping = 3
mon_decimal_point = ","
mon_thousands_sep = " "
mon_grouping = 3
positive_sign = ""
negative_sign = "-"
currency_symbol = "EUR"
frac_digits = 2
p_cs_precedes = 0
n_cs_precedes = 0
p_sep_by_space = 2
n_sep_by_space = 2
p_sign_posn = 1
n_sign_posn = 1
int_curr_symbol = "EUR "
int_frac_digits = 2
int_p_cs_precedes = 0
int_n_cs_precedes = 0
int_p_sep_by_space = 2
int_n_sep_by_space = 2
int_p_sign_posn = 1
int_n_sign_posn = 1
For readability, the characters in grouping and mon_grouping should be displayed as
decimal numbers.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void print_grouping(const char *grouping)
{
    for (int i = 0; grouping[i] != '\0'; i++)
        printf("%d ", (unsigned char)grouping[i]);

    putchar('\n');
}
void print_loc(const struct lconv loc)
{
	printf("decimal_point = \"%s\"\n", loc.decimal_point);
	printf("thousands_sep = \"%s\"\n", loc.thousands_sep);
	printf("grouping = ");
	print_grouping(loc.grouping);
	printf("mon_decimal_point = \"%s\"\n", loc.mon_decimal_point);
	printf("mon_thousands_sep = \"%s\"\n", loc.mon_thousands_sep);
	printf("mon_grouping = ");
	print_grouping(loc.mon_grouping);
	printf("positive_sign = \"%s\"\n", loc.positive_sign);
	printf("negative_sign = \"%s\"\n", loc.negative_sign);
	printf("currency_symbol = \"%s\"\n", loc.currency_symbol);
	printf("frac_digits = %d\n", loc.frac_digits);
	printf("p_cs_precedes = %d\n", loc.p_cs_precedes);
	printf("n_cs_precedes = %d\n", loc.n_cs_precedes);
	printf("p_sep_by_space = %d\n", loc.p_sep_by_space);
	printf("n_sep_by_space = %d\n", loc.n_sep_by_space);
	printf("p_sign_posn = %d\n", loc.p_sign_posn);
	printf("n_sign_posn = %d\n", loc.n_sign_posn);
	printf("int_curr_symbol = \"%s\"\n", loc.int_curr_symbol);
	printf("int_frac_digits = %d\n", loc.int_frac_digits);
	printf("int_p_cs_precedes = %d\n", loc.int_p_cs_precedes);
	printf("int_n_cs_precedes = %d\n", loc.int_n_cs_precedes);
	printf("int_p_sep_by_space = %d\n", loc.int_p_sep_by_space);
	printf("int_n_sep_by_space = %d\n", loc.int_n_sep_by_space);
	printf("int_p_sign_posn = %d\n", loc.int_p_sign_posn);
	printf("int_n_sign_posn = %d\n", loc.int_n_sign_posn);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		if (argc < 2)
		{
			printf("Error. Too few arguments\nusage: locale_format <locale>\n");
			exit(EXIT_FAILURE);
		}
		if (argc > 2)
		{
			printf("Error. Too many arguments\nusage: locale_format <locale>\n");
			exit(EXIT_FAILURE);
		}
	}
	char *new_loc = setlocale(LC_ALL, argv[1]);
	if (new_loc == NULL)
	{
		printf("Failed to set native locale.\n");
		return 1;
	}
	const struct lconv *loc = localeconv();
	print_loc(*loc);
}
