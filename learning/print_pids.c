#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_pid;
	pid_t parent_pid;

	my_pid = getpid();
	parent_pid = getppid();

	printf("Bro's pd: %u\n", my_pid);
	printf("Parent's pd: %u\n", parent_pid);

	return(0);
}
