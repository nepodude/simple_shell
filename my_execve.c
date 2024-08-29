#include "shell.h"
/**
* _execve - Just executes codes hahaha
* @filename: the name of code/file we execute.
* @arg: the arguments passed to the executables.
* @envp: enviroment variables pass to execve.
* Return: int 0 on success and -1 on failure.
 */
int _execve(const char *filename, char *const arg[], char *const envp[])
{
	char *dir, *path = NULL;
	int exec_status, i = 0;

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
		perror("execve");
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
 * codename_maker - Concatenates directory and filename ,executes the command
 * @dir: Directory name
 * @filename: File name to execute
 * @arg: Arguments to pass to execve
 * @envp: Environment variables to pass to execve
 * Return: 0 on success, -1 on failure
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
		free(full_path);
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
