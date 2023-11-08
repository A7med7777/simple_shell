#include "shell.h"

/**
 * read_input - Reads input from the standard input stream and stores it in
 * the given input buffer.
 *
 * @input: A pointer to a character array where the input will be stored.
 * Return: `0` on success, `-1` if end of file is encountered, otherwise exits
 * with an error message on failure.
 */
int read_input(char *input)
{
	if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
	{
		if (feof(stdin))
		{
			return (-1);
		}
		else
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
