#include "shell.h"

/**
 * execute_command - Executes the specified command along with its arguments.
 *
 * @command: A string representing the command to be executed.
 * @commands: An array of strings representing the command and its arguments.
 */
void execute_command(char *command, char *commands[])
{
	pid_t pid;
	int status;

	if (command == NULL)
		return;
	if (strcmp(command, "exit") == 0)
	{
		handle_exit(0);
	}
	else if (strcmp(command, "cd") == 0)
	{
		char *directory = commands[1];

		handle_cd(directory);
	}
	else if (strcmp(command, "env") == 0)
	{
		handle_env();
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execvp(command, commands) == -1)
			{
				perror("Command not found");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
}
