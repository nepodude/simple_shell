#include "shell.h"

/**
* _getline - gets the line from stdin.
* Return: the entered thing without
* the new line character.
*/

char *_getline()
{
	unsigned long int n = 0;

	char *lineptr = NULL;

	int ch_read;

	ch_read = getline(&lineptr, &n, stdin);
	if (ch_read == -1)
	{
		perror("getline");
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	if (lineptr[ch_read - 1] == '\n')
	{
		lineptr[ch_read - 1] = '\0';
	}
	return (lineptr);
}
