#include "shell.h"

/**
 * main - this will be used to get the command using getline, tokenize it using
 * tokenizer, fork in order to create a .
 */

int main(void)
{
	char **args;
	pid_t child_pid;
	int status;
	char *lineOfCommand = NULL;
	ssize_t read;
	size_t n = 0;

	while (1)
	{
		printf("$ ");
		
		read = getline(&lineOfCommand, &n, stdin);
		if (read == -1)
		{
			free(lineOfCommand);
			perror("failed to read");
			exit(EXIT_FAILURE);
		}

		lineOfCommand[strcspn(lineOfCommand, "\n")] = '\0';
		args = tokenizer(lineOfCommand, " ");
		child_pid = fork();

		if (child_pid < 0)
		{
			perror("failed to fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("failed executing");
				exit(EXIT_FAILURE);

			}
		}
		else 
			wait(&status);
	}
	return (0);
}
