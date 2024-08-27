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

char *my_getline();
void my_wait();
int my_execve();
int string_checker(char *str1, const char *str2);
char *my_strtok(char *str, const char *delim);
int _strlen(char *s);
char *my_strtok(char *str, const char *delim);
char *_strchr(char *s, char c);

#endif
