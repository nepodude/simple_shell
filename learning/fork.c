#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	pid_t mypid;
	int status;
	
	mypid = fork();
	
	if (mypid == 0)
	{
		printf("I am child\n");
		sleep(3);
	}
	
	if (mypid > 0)
	{

		printf("Waiting for my child.\n");
		wait(&status);
		printf("I am parent\n");
	}

	printf("parent: %d\tchild: %d\n", getppid(), getpid());
}
