#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t read;

	printf("$ ");
	read = getline(&line, &length, stdin);

	while (read != -1) {
		printf("%s", line);
		printf("size is %lu", length);
		printf("$ ");
		read = getline(&line, &length, stdin);
	}

	free(line);

	return 0;
}

