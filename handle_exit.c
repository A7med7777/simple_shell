#include "shell.h"

/**
 * handle_exit - Exits the shell program with the specified exit status.
 *
 * @status: The exit status code.
 */
void handle_exit(int status)
{
	printf("Exiting shell\n");
	exit(status);
}
