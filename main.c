#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "shell.h"

int main(){

	int char_read;
	char *arguments[1024];
	pid_t mypid;
	long unsigned int *n = 0;
	char *lineptr = NULL;

	while (1){
		printf("$");
		char_read = getline(&lineptr, n, stdin);
		if(char_read == -1){
			perror("getline");
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		if(lineptr[char_read - 1] == '\n'){
			lineptr[char_read - 1] = '\0';
		}
		arguments[0] = lineptr;
		arguments[1] = NULL;

		mypid = fork();
		if(mypid == 0){
			if(execve(arguments[0], arguments, NULL) == -1){
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else if(mypid > 0){
			int status;
			wait(&status);
		}
	}
	free(lineptr);
	return (0);
}
