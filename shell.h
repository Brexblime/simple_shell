#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define TOKEN_DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024
void main_loop(void);
int _strlen(char *str);
char *read_line(void);
void execute_command(char **args);
char **parse_line(char *line);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void execute_env(void);
#endif