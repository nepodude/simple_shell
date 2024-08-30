#include "shell.h"

/**
 * *_strdup - copies a string input
 * @str: string input to put to a new location
 *
 * Return: pointer to the copied string (Success), NULL (Error)
 */
char *_strdup(char *str)
{
	char *duplicate_str;

	if (str == NULL)
	{
		return (NULL);
	}

	duplicate_str = malloc((strlen(str) + 1) * sizeof(char));
	if (duplicate_str == NULL)
	{
		return (NULL);
	}
	_strcpy(duplicate_str, str);
	return (duplicate_str);
}
