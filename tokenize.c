#include "shell.h"

/**
 * tokenize - takes a string of words and returns their array with some delim.
 * @command: pointer to the large string.
 * @delim: pointer to the delimiter to use.
 * Return: an array of string pointers.
 */

char **tokenize(char *command, char *delim)
{
	char **argv;
	char *token;
	char *copy_command;
	int i = 0;

	copy_command = strdup(command);
	if (copy_command == NULL)
		exit(EXIT_FAILURE);
	token = strtok(copy_command, delim);
	 
	while(token)
	{
		argv[i] = malloc((strlen(token) + 1) * sizeof(char));
		if (argv[i] == NULL)
			exit(EXIT_SUCCESS);
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	free(copy_command);
	return argv;
}
