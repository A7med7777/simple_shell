#include "shell.h"

/**
 * parse_input - Parses the input string into individual commands using
 * specified delimiters.
 *
 * @input: The input string to be parsed.
 * @commands: An array of strings to store the parsed commands.
 * @delimiters: A string containing delimiters used for tokenization.
 */
void parse_input(char *input, char *commands[], char *delimiters)
{
	char *token;
	int i = 0;
	char *temp = strdup(input);

	if (temp == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(temp, delimiters);
	while (token != NULL)
	{
		commands[i] = strdup(token);
		if (commands[i] == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, delimiters);
	}
	commands[i] = NULL;

	free(temp);
}
