#include "shell.h"

/**
* _printf - writes the character c to stdout
* @chars: characters to priint.
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _printf(char *chars)
{
	ssize_t result;

	while (*chars != '\0')
	{
		result = write(1, chars, 1);
		if (result == -1)
		{
			return (-1);
		}
		chars++;
	}
	return (0);
}

/**
* _printf_err - writes the characters to stderr
* @chars: characters to print.
* Return: On success 0.
* On error, -1 is returned, and errno is set appropriately.
*/
int _printf_err(char *chars)
{
	ssize_t result;

	while (*chars != '\0')
	{
		result = write(2, chars, 1);
		if (result == -1)
		{
			return (-1);
		}
		chars++;
	}
	return (0);
}

