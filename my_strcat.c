#include "shell.h"
/**
 * _strcat - concatenating two  strings
 * @dest:char input
 * @src:char input
 * Return:char out of the function
 */
char *_strcat(char *dest, char *src)
{
char *s = dest;
while (*dest)
{
dest++;
}
while (*src)
{
*dest = *src;
dest++;
src++;
}
*dest = '\0';
return (s);
}