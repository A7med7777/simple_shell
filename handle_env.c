#include "shell.h"

/**
 * handle_env - Displays the environment variables to the standard output.
 */
void handle_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
