#include "shell.h"

/**
* _strtok - tokenizes a large string.
* @str: string one to check in haha
* @delim: a delimiter.
* Return: current pointer.
*/

char *_strtok(char *str, const char *delim)
{
	static char *saved_str;

	char *start;

	char *end;

	if (str != NULL)
	{
		saved_str = str;
	}
	if (saved_str == NULL)
	{
		return (NULL);
	}
	start = saved_str;
	while (*start && string_checker(start, delim))
	{
		start++;
	}

	if (*start == '\0')
	{
		saved_str = NULL;
		return (NULL);
	}
	end = start;
	while (*end && !string_checker(end, delim))
	{
		end++;
	}
	if (*end)
	{
		*end = '\0';
		saved_str = end + 1;
	} else
	{
		saved_str = NULL;
	}
	return (start);
}

/**
* string_checker - verifies similarity of two string.
* @str1: the first string.
* @str2: the second string.
* Return: 1 match and 0 otherwise.
*/

int string_checker(char *str1, const char *str2)
{
	while (*str2)
	{
		if (*str1 == *str2)
		{
			return (1);
		}
		str2++;
	}
	return (0);
}
