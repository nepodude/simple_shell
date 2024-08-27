#include "shell.h"

/**
* main - runs the code from the stdin.
* Return: 0 on sucess.

*crete execve check if code belongs in $PATH
 */

int main(void)
{
	char *lineptr;
	char *arguments[2];
	pid_t mypid;

	while (1)
	{
		printf("$ ");
		lineptr = my_getline();
 		arguments[0] = lineptr;
		arguments[1] = NULL;

		mypid = fork();
		if (mypid == 0)
		{
			if (execvp(arguments[0], arguments) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else if (mypid > 0)
		{
			my_wait();
		}
		else
		{
			perror("fork");
			free(lineptr);
			exit(EXIT_FAILURE);
		}
	}
	free(lineptr);
	return (0);
}
