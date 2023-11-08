#include "shell.h"

/**
 * main - The entry point of the program. Handles command line arguments,
 * reads input,
 * parses and executes commands, and provides an interactive shell or reads
 * commands
 * from a file based on the input.
 *
 * @argc: An integer representing the number of command line arguments.
 * @argv: An array of strings representing the command line arguments.
 * Return: `0` on successful execution.
 */
int main(int argc, char *argv[])
{
	char input[MAX_INPUT_SIZE];
	char *commands[MAX_ARGS];
	char delimiters[] = " \t\n";
	int status = 0;

	if (argc > 1)
	{
		FILE *file = fopen(argv[1], "r");

		if (file == NULL)
		{
			perror("Error opening file");
			exit(EXIT_FAILURE);
		}
		while (fgets(input, MAX_INPUT_SIZE, file) != NULL)
		{
			parse_input(input, commands, delimiters);
			execute_command(commands[0], commands);
		}
		fclose(file);
	}
	else
	{
		while (1)
		{
			display_prompt();
			if (read_input(input) == 0)
			{
				parse_input(input, commands, delimiters);
				execute_command(commands[0], commands);
			}
			else
			{
				handle_exit(status);
			}
		}
	}
	return (0);
}
