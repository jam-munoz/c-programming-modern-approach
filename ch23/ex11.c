/* Write a call of memset that replaces the last n characters in a
null-terminated string s with ! characters.*/
#include <string.h>

memset(s + strlen(s) - n, '!', n);
