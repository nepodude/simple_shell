#include "shell.h"

/**
 * char *_strcpy - this is a thing that copies the string pointed to by src
 * @dest: will copy to this
 * @src: will  copy from this
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;
	int b = 0;

	while (*(src + a) != '\0')
	{
		a++;
	}
	for ( ; b < a ; b++)
	{
		dest[b] = src[b];
	}
	dest[a] = '\0';
	return (dest);
}
