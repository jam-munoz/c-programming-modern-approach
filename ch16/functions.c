#include <stdbool.h>
#include <stdio.h>

/* (a) Declare structure variables named c1, c2, and c3, each having members real and imaginary of type double.
(b) Modify the declaration in part (a) so that c1’s members initially have the values 0.0 and
1.0, while c2’s members are 1.0 and 0.0 initially. (c3 is not initialized.)*/
struct 
{
  double real;
  double imaginary;
} c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;
//(c) Write statements that copy the members of c2 into c1. Can this be done in one statement, or does it require two?
c1 = c2;
//(d) Write statements that add the corresponding members of c1 and c2, storing the result in c3.
c3.real = c1.real + c2.real;
c3.imaginary = c1.imaginary + c2.imaginary;

/* (a) Show how to declare a tag named complex for a structure with two members, real and imaginary, of type double.*/
struct complex
{
  double real;
  double imaginary;
};
//(b) Use the complex tag to declare variables named c1, c2, and c3.
struct complex c1, c2, c3;
/*(c) Write a function named make_complex that stores its two arguments (both of type
double) in a complex structure, then returns the structure. */
struct complex make_complex(double x, double y)
{
  return (struct complex) {real, imaginary};
}
/*(d) Write a function named add_complex that adds the corresponding members of its
arguments (both complex structures), then returns the result (another complex structure).*/
struct complex add_complex(struct complex x, struct complex y)
{
  return (struct complex) x.real + y.real, x.imaginary + y.imaginary;
}

/* Repeat Exercise 3, but this time using a type named Complex.*/
typedef struct 
{
  double real;
  double imaginary;
} Complex;
Complex c1, c2, c3;

Complex make_complex(double x, double y)
{
  return (Complex) {real, imaginary}
}
Complex add_complex(Complex x, Complex y)
{
  return (Complex) x.real + y.real, x.imaginary + y.imaginary;
}

/* Write the following functions, assuming that the date structure contains three members:
month, day, and year (all of type int).
(a) Returns the day of the year (an integer between 1 and 366) that corresponds to the date d.*/
int day_of_year(struct date d)
{
const int month_days[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
  bool leap = false;
  if (d.month < 2)
    return d.day;
  if (d.month == 2)
    return d.day + month_days[d.month-2];
  if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0))
    leap = true;
  if (leap == true)
    return d.day + 1 + month_days[d.month-2];
  return d.day + month_days[d.month-2];
}
//(b) Returns –1 if d1 is an earlier date than d2, +1 if d1 is a later date than d2, and 0 if d1 and d2 are the same.
int compare_dates(struct date d1, struct date d2)
{
  if (d1.year < d2.year)
    return -1;
  if (d1.year > d2.year)
    return 1;
  int d1day = day_of_year(d1);
  int d2day = day_of_year(d2);
  if (d1day < d2day)
    return -1;
  if (d1day > d2day)
    return 1;
  return 0;
}

/* Write the following function, assuming that the time structure contains three members:
hours, minutes, and seconds (all of type int).
struct time split_time(long total_seconds);
total_seconds is a time represented as the number of seconds since midnight. The
function returns a structure containing the equivalent time in hours (0–23), minutes (0–59), and seconds (0–59).*/
struct time split_time(long total_seconds)
{
  struct time t;
  t.hours = (total_seconds / 3600) % 24;
  t.minutes = (total_seconds % 3600) / 60;
  t.seconds = total_seconds % 60;
  return t;
}

/* Assume that the fraction structure contains two members: numerator and denominator (both of type int). 
Write functions that perform the following operations on fractions:
(a) Reduce the fraction f to lowest terms. Hint: To reduce a fraction to lowest terms, first
compute the greatest common divisor (GCD) of the numerator and denominator. Then
divide both the numerator and denominator by the GCD.
The fractions f, f1, and f2 will be arguments of type struct fraction; each function
will return a value of type struct fraction. The fractions returned by the functions in
parts (b)–(e) should be reduced to lowest terms. Hint: You may use the function from part
(a) to help write the functions in parts (b)–(e).*/
struct fraction lowest_term(struct fraction f)
{
  int temp;
  int gcd = f.denominator;
  int n = f.numerator;
  while (n > 0)
  {
    temp = gcd % n;
    gcd = n;
    n = temp;
  }
  f.numerator /= gcd;
  f.denominator /= gcd;
  return f;
}
// (b) Add the fractions f1 and f2.
struct fraction add_fraction(struct fraction f1, struct fraction f2)
{
  f1.numerator *= f2.denominator;
  f2.numerator *= f1.denominator;
  f1.numerator += f2.numerator;
  f1.denominator *= f2.denominator;
  return lowest_term(f1);
}
// (c) Subtract the fraction f2 from the fraction f1.
struct fraction substract_fraction(struct fraction f1, struct fraction f2)
{
  f1.numerator *= f2.denominator;
  f2.numerator *= f1.denominator;
  f1.numerator -= f2.numerator;
  f1.denominator *= f2.denominator;
  return lowest_term(f1);
}
// (d) Multiply the fractions f1 and f2.
struct fraction multiply_fraction(struct fraction f1, struct fraction f2)
{
  f1.numerator *= f2.numerator;
  f1.denominator *= f2.denominator;
  return lowest_term(f1);
}
// (e) Divide the fraction f1 by the fraction f2.
struct fraction divide_fraction(struct fraction f1, struct fraction f2)
{
  f1.numerator *= f2.denominator;
  f1.denominator *= f2.numerator;
  return lowest_term(f1);
}

/* Let colour be the following structure:*/
struct colour {
int red;
int green;
int blue;
};
/*(a) Write a declaration for a const variable named MAGENTA of type struct colour
whose members have the values 255, 0, and 255, respectively.
(b) (C99) Repeat part (a), but use a designated initializer that doesn’t specify the value of
green, allowing it to default to 0.*/
const struct colour MAGENTA = {255, 0, 255};
const struct colour MAGENTA = {255, .blue = 255};


/* Write the following functions. (The colour structure is defined in Exercise 8.)
(a) struct colour make_colour(int red, int green, int blue);
Returns a colour structure containing the specified red, green, and blue values. If any argu-
ment is less than zero, the corresponding member of the structure will contain zero instead.
If any argument is greater than 255, the corresponding member of the structure will contain 255.
(e) struct colour darker(struct colour c);
Returns a colour structure that represents a darker version of the colour c. The structure is identical 
to c, except that each member has been multiplied by 0.7 (with the result truncated to an integer).*/
struct colour make_colour(int red, int green, int blue)
{
  if (red < 0)
    red = 0;
  else if (red > 255)
    red = 255;
  if (green < 0)
    green = 0;
  else if (green > 255)
    green = 255;
  if (blue < 0)
    blue = 0;
  else if (blue > 255)
    blue = 255;
  return (struct colour) {red, green, blue};
}
// (b) Returns the value of c’s red member.
int getRed(struct colour c)
{
  return colour.red;
}
// (c) Returns true if the corresponding members of colour1 and colour2 are equal.
bool equal_colour(struct colour colour1, struct colour colour2)
{
  return ((colour1.red == colour2.red) && (colour1.green == colour2.green) && (colour1.blue == colour2.blue));
}
/* (d) Returns a colour structure that represents a brighter version of the colour c. The structure is
identical to c, except that each member has been divided by 0.7 (with the result truncated to
an integer). However, there are three special cases: ** */
struct colour brighter(struct colour c)
{ // (1) If all members of c are zero, the function returns a colour whose members all have the value 3.
  if ((c.red == 0) && (c.green == 0) && (c.blue == 0))
    return (struct colour) {3, 3 ,3};
  float r, g, b;
  // (2) If any member of c is greater than 0 but less than 3, it is replaced by 3 before the division by 0.7. 
  if (c.red > 0 && c.red < 3)
    c.red = 3;
  if (c.green > 0 && c.green < 3)
    c.green = 3;
  if (c.blue > 0 && c.blue < 3)
    c.blue = 3;
  // (3) If dividing by 0.7 causes a member to exceed 255, it is reduced to 255.
  r = c.red / 0.7f;
  if (r > 255)
    r = 255;
  g = c.green / 0.7f;
  if (g > 255)
    g = 255;
  b = c.blue / 0.7f;
  if (b > 255)
    b = 255;
  return (struct colour) {(int) r, (int) g, (int) b};
}

/* The following structures are designed to store information about objects on a graphics screen:
A point structure stores the x and y coordinates of a point on the screen. A rectangle
structure stores the coordinates of the upper left and lower right corners of a rectangle. Write
functions that perform the following operations on a rectangle structure r passed as an argument:*/
struct point 
{
  int x, y;
};
struct rectangle 
{
  struct point upper_left, lower_right;
};
// (a) Compute the area of r.
int area_r(struct rectangle r)
{
  int x = r.lower_right.x - r.upper_left.x;
  int y = r.upper_left.y - r.lower_right.y;
  return (x * y);
}
/*(b) Compute the center of r, returning it as a point value. If either the x or y coordinate 
of the center isn’t an integer, store its truncated value in the point structure.*/
struct point center_r(struct rectangle r)
{
  int x = (r.lower_right.x - r.upper_left.x) / 2;
  int y = (r.upper_left.y - r.lower_right.y) / 2;
  return (struct point) {x, y};
}
/*(c) Move r by x units in the x direction and y units in the y direction, returning 
the modified version of r. (x and y are additional arguments to the function.) */
struct rectangle move_r(struct rectangle r, int x, int y)
{
  r.lower_right.x += x;
  r.lower_right.y += y;
  r.upper_left.x += x;
  r.upper_left.y += y;
  return r;
}
//(d) Determine whether a point p lies within r, returning true or false. (p is an additional argument of type struct point.)
bool p_inside(struct rectangle r, struct point p)
{
  return (r.upper_left.x < p.x && p.x < r.lower_right.x && r.lower_right.y < p.y && p.y < r.upper_left.y);
}

/* Let shape be the structure tag declared in Exercise 13. Write functions that perform the
following operations on a shape structure s passed as an argument:*/
struct shape {
  int shape_kind;
  /* RECTANGLE or CIRCLE */
  struct point center;
  /* coordinates of center */
  union {
    struct {
        int height, width;
      } rectangle;
      struct {
        int radius;
      } circle;
    } u;
} s;
//(a) Compute the area of s.
int area_s(struct shape s)
{
  if (shape_kind == RECTANGLE)
    return s.u.rectangle.height * s.u.rectangle.width;
  else return (s.u.circle.radius * s.u.circle.radius * (22.0/7.0));
}
/*(b) Move s by x units in the x direction and y units in the y direction, returning 
the modified version of s. (x and y are additional arguments to the function.)*/
struct shape move_center(struct shape s, int x, int y)
{
  s.center.x += x;
  s.center.y += y;
  return s;
}
//(c) Scale s by a factor of c (a double value), returning the modified version of s. (c is an additional argument to the function.)
struct shape scale_s(struct shape s, double c)
{
  if (shape_kind == RECTANGLE)
  {
    s.u.rectangle.height *= c;
    s.u.rectangle.width *= c;
  }
  else s.u.circle.radius *= c;
  return s;
}

//(a) Declare a tag for an enumeration whose values represent the seven days of the week.
enum week_days = {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};
//(b) Use typedef to define a name for the enumeration of part (a).
typedef enum = {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} Day;

/* (a) Each square of a chessboard can hold one piece—a pawn, knight, bishop, rook, queen,
or king—or it may be empty. Each piece is either black or white. Define two enumerated
types: Piece, which has seven possible values (one of which is “empty”), and Color,
which has two.*/
typedef enum {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING} Piece;
typedef enum {BLACK, WHITE} Colour;
//(b) Using the types from part (a), define a structure type named Square that can store both the type of a piece and its colour.
typedef struct
{
  Piece piece;
  Colour colour;
} Square;
//(c) Using the Square type from part (b), declare an 8 × 8 array named board that can store the entire contents of a chessboard.
/* (d) Add an initializer to the declaration in part (c) so that board’s initial value corresponds
to the usual arrangement of pieces at the start of a chess game. A square that’s not occupied
by a piece should have an “empty” piece value and the colour black. */
Square board[8][8] = { 
    {{ROOK,  WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN, WHITE}, {KING,  WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK,  WHITE}},
    {{PAWN,  WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,  WHITE}, {PAWN,  WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,  WHITE}},
    {{EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}},
    {{EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}},
    {{EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}},
    {{EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}},
    {{PAWN,  BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,  BLACK}, {PAWN,  BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,  BLACK}},
    {{ROOK,  BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN, BLACK}, {KING,  BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK,  BLACK}},
}

/* Declare a structure with the following members whose tag is pinball_machine:
name – a string of up to 40 characters
year – an integer (representing the year of manufacture)
type – an enumeration with the values EM (electromechanical) and SS (solid state)
players – an integer (representing the maximum number of players) */
struct pinball_machine
{
  char name[41];
  int year;
  enum { EM, SS } type;
  int players;
}

// Suppose that the direction variable is declared in the following way:
enum {NORTH, SOUTH, EAST, WEST} direction;
/* Let x and y be int variables. Write a switch statement that tests the value of direc-
tion, incrementing x if direction is EAST, decrementing x if direction is WEST,
incrementing y if direction is SOUTH, and decrementing y if direction is NORTH.*/
switch (direction)
{
  case EAST: i++; break;
  case WEST: i--; break;
  case NORTH: y++; break;
  case SOUTH: y--; break;
  default: break;
}

// Let chess_pieces be the following enumeration:
enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};
/* (a) Write a declaration (including an initializer) for a constant array of integers named
piece_value that stores the numbers 200, 9, 5, 3, 3, and 1, representing the value of each
chess piece, from king to pawn. (The king’s value is actually infinite, since “capturing” the
king (checkmate) ends the game, but some chess-playing software assigns the king a large value such as 200.)
(b) (C99) Repeat part (a), but use a designated initializer to initialize the array. Use the enu-
meration constants in chess_pieces as subscripts in the designators. (Hint: See the last question in Q&A for an example.)*/
const int piece_value[] = {200, 9, 5, 3, 3, 1};
const int piece_value[] = {
    [KING] = 200, 
    [QUEEN] = 9,
    [ROOK] = 5, 
    [BISHOP] = 3,
    [KNIGHT] = 3,
    [PAWN] = 1
};