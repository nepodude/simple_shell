#include "shell.h"

/**
 * execute - executes the command.
 */

int execute(const char *command)
{
	pit_t pidpid;

	pidpid = fork();
	if(pidpid < 0)
	{
		perror("fork");
		exit(EXIT FAILURE);
	}
	else if (pidpid == 0)
	{
		execve(command, command, (char *)NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
