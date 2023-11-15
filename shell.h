#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 100
#define MAX_PATH_LENGTH 1024

extern char **environ;

void display_prompt(void);
int read_input(char *input);
void parse_input(char *input, char *commands[], char *delimiters);
void execute_command(char *command, char *commands[]);
void handle_exit(int status);
void handle_cd(char *directory);
void handle_env(void);

#endif
