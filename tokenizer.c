#include "shell.h"

/**
 * tokenizer - takes a string of words and returns their array with some delim.
 * @command: pointer to the large string.
 * @delim: pointer to the delimiter to use.
 * Return: an array of string pointers.
 */

char **tokenizer(char *command, char *delim)
{
	char **argv;
	char *token;
	char *copy_command;
	char *copy_command1;
	int i = 0, numOfTokens = 0;

	copy_command1 = strdup(command);
	if (copy_command1 == NULL)
		exit(EXIT_FAILURE);
	token = strtok(copy_command1, delim);
	while (token)
	{
		numOfTokens++;
		token = strtok(NULL, delim);
	}

	argv = malloc((numOfTokens + 1) * sizeof(char *));

	copy_command = strdup(command);
	if (copy_command == NULL)
		exit(EXIT_FAILURE);
	token = strtok(copy_command, delim);
	while (token)
	{
		argv[i] = malloc((strlen(token) + 1) * sizeof(char));
		if (argv[i] == NULL)
			exit(EXIT_FAILURE);
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	free(copy_command);
	free(copy_command1);
	return (argv);
}
