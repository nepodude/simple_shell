#include "shell.h"
/**
* _execve - Just executes codes hahaha
* @filename: the name of code/file we execute.
* @arg: the arguments passed.
* @envp: enviroment passed to main then to execve.
* Return: int 0 on success and -1 otherwise.
 */
int _execve(const char *filename, char *const arg[], char *const envp[])
{
	char *dir, *path = NULL;
	int exec_status;
	int i = 0;

	for (; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break;
		}
	}
	if (path == NULL)
	{
		fprintf(stderr, "PATH environment variable not found\n");
		return (-1);
	}
	if (_strchr((char *)filename, '/') != NULL)
	{
	exec_status = execve(filename, arg, envp);
	if (exec_status == -1)
	{
		perror("exeve");
		return (-1);
	}
	}
	dir = _strtok(path, ":");
	for (; dir != NULL; dir = _strtok(NULL, ":"))
	{
		if (codename_maker(dir, (char *)filename, arg, envp) == -1)
		{
			return (-1);
		}
		else
		{
			return (0);
		}
	}
	fprintf(stderr, "%s: command not found\n", filename);
	return (-1);
}

/**
* codename_maker - helps execve that's all.
* @dir: helper
* @filename: helper
* @arg: helper.
* @envp: helper.
* Return: -1 on failure and 0 on success.
 */

int codename_maker(char *dir, char *filename,
char *const arg[], char *const envp[])
{
	char *full_path;
	int exec_status;

	full_path = malloc(_strlen(dir) + strlen(filename) + 2);
	if (full_path == NULL)
	{
		perror("malloc");
		return (-1);
	}
	_strcpy(full_path, dir);
	_strcat(full_path, "/");
	_strcat(full_path, (char *)filename);

	exec_status = execve(full_path, arg, envp);
	free(full_path);
	if (exec_status != -1)
	{
		return (0);
	}
	else if (errno != ENOENT)
	{
		perror("execve");
		return (-1);
	}
	return (-1);
}
