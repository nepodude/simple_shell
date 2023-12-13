#include "shell.h"

/**
 * main - this will be used to get the command, execute it, show the prompt.
 */

int main(void)
{
	char command[256];
	char *args[20];
	pid_t pid;
	int status, i;
	char *token;

	while (1)
	{
		printf("$");

		if (fgets(command, sizeof(command), stdin) == NULL)
		{	
			printf("\n");
			return (0);
		}

		command[strcspn(command, "\n")] = '\0';
		token = strtok(command, " ");

		for (i = 0; i < 20 && token != NULL; i++)
		{
			args[i] = token;
			token = strtok(command, " ");
		}
		
		pid = fork();
		if (pid < 0)
			perror("fork error");
		else if (pid == 0)
		{
			if (execvp(args[0], args) < 0)
			{
				perror(args[0]);
				exit(EXIT_FAILURE);
			}
		}

		pid = waitpid(pid, &status, 0);
		
		if (pid  < 0)
			perror("waitpid error");
	}
	return (0);
}
