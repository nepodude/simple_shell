#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>

char *_getline();
void _wait();
int _execve();
int string_checker(char *str1, const char *str2);
int _strlen(char *s);
char *_strtok(char *str, const char *delim);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
