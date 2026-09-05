/* Replace the test condition in the following if statement by a single call of strchr:
if (ch == 'a' || ch == 'b' || ch == 'c') …*/
#include <string.h>

if (strchr("abc", ch))
