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
		arguments = get_inputs(&lineptr);
		if (arguments == NULL)
		{
			continue;
		}
		mypid = fork();
		if (mypid == 0)
		{
			handle_child_process(arguments, envp, lineptr);
		}
		else if (mypid > 0)
		{
			_wait();
			free(lineptr);
			lineptr = NULL;
			free_args(arguments);
		}
		else
		{
			perror("fork");
			free(lineptr);
			free_args(arguments);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

/**
* parse_input - parses input string.
* @input: input string to parse.
* Return: resulting array of parsed strings.
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
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = _strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	return (args);
}

/**
* free_args - frees allocated memory.
* @args: something to free.
* Return: nothing.
 */
void free_args(char **args)
{
	if (args)
	{
		free(args);
	}
}

/**
* get_inputs - gets inputs and deals with them.
* @lineptr: line pointer
* Return: pointer to pointers which are arguments.
 */

char **get_inputs(char **lineptr)
{
	char **arguments;

	*lineptr = _getline();
	if (feof(stdin))
	{
		exit(EXIT_SUCCESS);
	}
	if (*lineptr == NULL)
	{
		free(*lineptr);
		return (NULL);
	}
	arguments = parse_input(*lineptr);
	if (arguments == NULL || arguments[0] == NULL)
	{
		free(*lineptr);
		free_args(arguments);
		return (NULL);
	}
	return (arguments);
}

/**
* handle_child_process - handles childs process
* @envp: environment.
* @lineptr: line pointer
* @arguments: arguments
* Return: nothing.
 */

void handle_child_process(char **arguments, char *envp[], char *lineptr)
{
	if (_execve(arguments[0], arguments, envp) == -1)
	{
		perror("execve");
		free(lineptr);
		free_args(arguments);
		exit(EXIT_FAILURE);
	}
}
