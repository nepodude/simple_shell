#include "shell.h"

/**
* main - runs the code from the stdin.
* @argc: number of passed arguments
* @argv: an array of argument strings;
* @envp: the current environment to play with haha
* Return: 0 on sucess.
*crete execve check if code belongs in $PATH
 */

int main(__attribute__((unused)) int argc,
__attribute__((unused)) char *argv[], char *envp[])
{
	char *lineptr;
	char **arguments;
	pid_t mypid;

	while (1)
	{
		lineptr = _getline();
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		if (lineptr == NULL)
		{
			free(lineptr);
			continue;
		}
		arguments = parse_input(lineptr);
		if (arguments == NULL || arguments[0] == NULL)
		{
			free(lineptr);
			free_args(arguments);
			continue;
		}
		mypid = fork();
		if (mypid == 0)
		{
			if (_execve(arguments[0], arguments, envp) == -1)
			{
				perror("execve");
				free(lineptr);
				free_args(arguments);
				exit(EXIT_FAILURE);
			}
		}
		else if (mypid > 0)
		{
			_wait();
		}
		else
		{
			perror("fork");
			free(lineptr);
			free_args(arguments);
			exit(EXIT_FAILURE);
		}
		free(lineptr);
		lineptr = NULL;
		free_args(arguments);
	}

	return (0);
}

/**
 */

char **parse_input(char *input)
{
	char **args = malloc(MAX_ARGS * sizeof(char *));
	char *token;
	int i = 0;

	if (!args)
	{
		perror("malloc");
		return (NULL);
	}
	token = _strtok(input, " \t\n");
	while(token != NULL && i < MAX_ARGS -1)
	{
		args[i++] = token;
		token = _strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	return(args);
}

/**
 */
void free_args(char **args)
{
	if(args)
	{
		free(args);
	}
}