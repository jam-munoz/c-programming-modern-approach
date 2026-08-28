/* Describe a simple way to “toggle” a bit (change it from 0 to 1 or from 1 to 0). Illustrate the
 technique by writing a statement that toggles bit 4 of the variable i.**/
i &= ~8;

/* Explain what effect the following macro has on its arguments. You may assume that the arguments have the same type.
 #define M(x,y) ((x)^=(y),(y)^=(x),(x)^=(y))*/
x = x ^ y;
y = y ^ (x ^ y) = x;
x = (x ^ y) ^ x = y;
swap.

