#include "main.h"
/**
 * _strlen - check the code
 * @s: input
 * Return: Always 0.
*/
int _strlen(char *s)
{
int counter  = 0;
while (s[counter] != '\0')
{
counter++;
}
return (counter);
}