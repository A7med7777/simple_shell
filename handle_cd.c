#include "shell.h"

/**
 * handle_cd - Handles the change of current directory based on the given
 * directory path.
 * Supports switching to the previous directory if no path is provided.
 *
 * @directory: A string representing the directory path to change to.
 */
void handle_cd(char *directory)
{
	static char previous_directory[MAX_PATH_LENGTH];

	if (directory == NULL || strcmp(directory, "-") == 0)
	{
		if (previous_directory[0] != '\0')
		{
			chdir(previous_directory);
			printf("Switched to previous directory: %s\n",
					previous_directory);
		}
		else
		{
			printf("No previous directory available\n");
		}
	}
	else
	{
		char current_directory[MAX_PATH_LENGTH];

		if (getcwd(current_directory, sizeof(current_directory)) != NULL)
		{
			strcpy(previous_directory, current_directory);
		}
		else
		{
			perror("getcwd error");
		}

		if (chdir(directory) == 0)
		{
			printf("Changed directory to: %s\n", directory);
		}
		else
		{
			perror("chdir error");
		}
	}
}
