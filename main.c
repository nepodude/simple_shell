#include "shell.h"

/**
* main - runs the code from the stdin.
* Return: 0 on sucess.

*crete execve check if code belongs in $PATH
 */

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[], char *envp[])
{
	char *lineptr;
	char *arguments[2];
	pid_t mypid;

	while (1)
	{	
		printf("$");
		lineptr = _getline();
 		arguments[0] = lineptr;
		arguments[1] = NULL;

		mypid = fork();
		if (mypid == 0)
		{
			if (_execve(arguments[0], arguments, envp) == -1)
			{
				perror("execve");
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
			exit(EXIT_FAILURE);
		}
	}
	free(lineptr);
	return (0);
}
