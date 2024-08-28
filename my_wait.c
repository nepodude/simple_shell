#include "shell.h"

/**
* _wait - performs the wait action.
* Return: nothing
*/

void _wait(void)
{
	int status;

	pid_t mypid = wait(&status);

	if (mypid == -1)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}
}
