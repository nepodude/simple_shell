#include "shell.h"

/**
 * main - this will be used to get the command using getline, tokenize it using
 * tokenizer, fork in order to create a .
 * Return: 0 on sucess.
 */

int main(void)
{
	char **args;
	pid_t child_pid;
	int status;
	char *lineOfCommand = NULL;
	ssize_t read;
	size_t n = 0;
	extern char **environ;

	while (1)
	{
		printf("#cisfun$ ");
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
			if (execve(args[0], args, environ) == -1)
			{
				printf("./shell: No such file or directory\n");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	return (EXIT_SUCCESS);
}
