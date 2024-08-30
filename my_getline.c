#include "shell.h"

/**
* _getline - gets the line from stdin.
* Return: the entered thing without
* the new line character.
*/

char *_getline(void)
{
	unsigned long int n = 0;
	char *lineptr = NULL;
	int ch_read;

	ch_read = getline(&lineptr, &n, stdin);
	if (ch_read == -1)
	{
		if (feof(stdin))
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			free(lineptr);
			exit(EXIT_FAILURE);
		}
	}
	if (ch_read > 0 && lineptr[ch_read - 1] == '\n')
	{
		lineptr[ch_read - 1] = '\0';
	}
	lineptr = trim_spaces(lineptr);
	if (lineptr == NULL || *lineptr == '\0' ||
	*lineptr == '\n')
	{
		free(lineptr);
		return (NULL);
	}
	return (lineptr);
}

/**
* trim_spaces - removes spaces.
* @lineptr: a string to trim.
* Return: a fine and trimmed string.
 */

char *trim_spaces(char *lineptr)
{
	char *start = lineptr;
	char *end;
	char *trimmed;

	while (*start && _isspace((unsigned char)*start))
	{
		start++;
	}
	if (*start == '\0')
	{
		return (_strdup(""));
	}
	end = start + _strlen(start) - 1;
	while (end > start && _isspace((unsigned char)*end))
	{
		end--;
	}
	*(end + 1) = '\0';
	trimmed = _strdup(start);
	free(lineptr);

	return (trimmed);
}

/**
* _isspace - checks if something is a space character.
* @c: the character to check.
* Return: retuns 1 on yes an 0 on no.
 */

int _isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v'
	|| c == '\f' || c == '\r');
}
