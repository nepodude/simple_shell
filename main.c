#include "shell.h"

/**
 * main - this will be used to get the command, execute it, show the prompt.
 */

int main(void)
{
	char **args;
	pid_t child_pid;
	int status;
	char *lineOfCommand = NULL;
	ssize_t read;
	size_t n;

	while (1)
	{
		printf("$ ");
		
		read = getline(&lineOfCommand, &n, stdin);
		if (read == -1)
		{
			free(lineOfCommand);
			perror("failed to read line");
			exit(EXIT_FAILURE);
		}

		lineOfCommand[strcspn(lineOfCommand, "\n")] = '\0';
		args = tokenizer(lineOfCommand, " ");
		child_pid = fork();

		if (child_pid < 0)
			perror("fork error");
		else if (child_pid == 0)
		{
			if (execve(args[0], args, NULL) < 0)
			{
				perror("Error:");
			}
		}

		wait(&status);
	}
	return (0);
}
