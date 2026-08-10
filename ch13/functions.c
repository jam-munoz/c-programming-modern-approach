/* (a) Write a function named capitalize that capitalizes all letters in its argument. The
argument will be a null-terminated string containing arbitrary characters, not just letters.
Use array subscripting to access the characters in the string. Hint: Use the toupper func-
tion to convert each character to upper-case.
(b) Rewrite the capitalize function, this time using pointer arithmetic to access the characters in the string. */
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void capitalize(char *characters)
{
    char *p = characters;
    while(*p)
    {
        *p = toupper(*p);
        p++;
    }
    return;
}

/* Write a function named censor that modifies a string by replacing every occurrence of
foo by xxx. For example, the string "food fool" would become "xxxd xxxl". Make
the function as short as possible without sacrificing clarity.*/
void censor(char *xxx)
{
    char *p = xxx;
    while(*p)
    {
        if (*p == 'f' || *p == 'o')
            *p = 'x';
        p++;
    }
    return;
}

/* Write the following function:
void get_extension(const char *file_name, char *extension);
file_name points to a string containing a file name. The function should store the exten-
sion on the file name in the string pointed to by extension. For example, if the file name
is "memo.txt", the function will store "txt" in the string pointed to by extension. If
the file name doesn’t have an extension, the function should store an empty string (a single
null character) in the string pointed to by extension. Keep the function as simple as pos-
sible by having it use the strlen and strcpy functions.*/
void get_extension(const char *file_name, char *extension)
{
    while(*file_name != '.')
        file_name++;
    file_name++;
    strcpy(extension, file_name);
}

/* Write the following function:
bool test_extension(const char *file_name, const char *extension);
file_name points to a string containing a file name. The function should return true if
the file’s extension matches the string pointed to by extension, ignoring the case of let-
ters. For example, the call test_extension("memo.txt", "TXT") would return
true. Incorporate the “search for the end of a string” idiom into your function. Hint: Use
the toupper function to convert characters to upper-case before comparing them.*/
bool test_extension(const char *file_name, const char *extension)
{
    int i;
    while (*file_name != '.')
        file_name++;
    file_name++;
    i = strcmp(file_name, extension);
    if (i == 0)
        return true;
    else return false;
}

/* Write the following function:
void remove_filename(char *url);
url points to a string containing a URL (Uniform Resource Locator) that ends with a file
name (such as "http://www.knking.com/index.html"). The function should
modify the string by removing the file name and the preceding slash. (In this example, the
result will be "http://www.knking.com".) Incorporate the “search for the end of a
string” idiom into your function. Hint: Have the function replace the last slash in the string
by a null character.*/
void remove_filename(char *url)
{
    char *p = &url[7];
    while (*p != '/')
        p++;
    if (*p == '/')
        *p = putchar('\0');
    return;
}

int main(void)
{
    char c[] = "http://www.knking.com/index.html";
    remove_filename(c);
    printf("%s\n", c);
}