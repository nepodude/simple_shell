#include "shell.h"

int _execve(const char *filename, char *const arg[], char *const envp[])
{
    char *path = NULL;
    char *dir, *full_path;
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
        return -1;
    }
    if (_strchr((char *)filename, '/') != NULL)
    {
        exec_status = execve(filename, arg, envp);
        if (exec_status == -1)
        {
            perror("exeve");
            return -1;
        }
    }
    dir = _strtok(path, ":");
    while (dir != NULL)
    {
        full_path = malloc(_strlen(dir) + strlen(filename) + 2);
        if (full_path == NULL)
        {
            perror("malloc");
            return -1;
        }
        _strcpy(full_path, dir);
        _strcat(full_path, "/");
        _strcat(full_path, (char *)filename);

        exec_status = execve(full_path, arg, envp);
        free(full_path); 
        if (exec_status != -1)
        {
            return 0;
        }
        else if (errno != ENOENT)
        {
            perror("execve");
            return -1;
        }
        dir = strtok(NULL, ":");
    }

    fprintf(stderr, "%s: command not found\n", filename);
    return -1;
}