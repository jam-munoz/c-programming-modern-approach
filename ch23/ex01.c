/* Extend the round_nearest function so that it rounds a floating-point number x to n dig-
its after the decimal point. For example, the call round_nearest(3.14159, 3) would
return 3.142. Hint: Multiply x by 10n, round to the nearest integer, then divide by 10n. Be
sure that your function works correctly for both positive and negative values of x.*/
#include <math.h>

double round_nearest(double x, double n)
{
	double	factor;

	factor = pow(10.0, n);
	x *= factor;
	if (x < 0.0)
		x = ceil(x - 0.5);
	else
		x = floor(x + 0.5);

	return x / factor;
}
