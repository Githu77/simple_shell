#include "shell.h"

/**
*execute_command - executes inputs
*@tokenized_command: required input form
*@command_type: the type
*
*
*
*
*
*
*
*/
void run_inp(char **tc, int inp_type)
{
	void (*func)(char **command);

	if (inp_type == EXTERNAL_COMMAND)
	{
		if (execve(tc[0], tc, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (inp_type == PATH_COMMAND)
	{
		if (execve(check_path(tc[0]), tc, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (inp_type == INTERNAL_COMMAND)
	{
		func = get_function(tc[0]);
		func(tc);
	}
	if (inp_type == INVALID_COMMAND)
	{
		print(name, STDERR_FILENO);
		print(": 1: ", STDERR_FILENO);
		print(tc[0], STDERR_FILENO);
		print(": not found\n", STDERR_FILENO);
		state = 127;
	}
}

