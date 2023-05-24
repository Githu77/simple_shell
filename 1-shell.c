#include "shell.h"

/**
*env - writeenvironnement
*@tokenized_command: command
*
*
*
*
*
*
*/

void env(char **tokenized_command __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print(environ[i], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
* quit - exits
* @tokenized_command: command
*
*
*
*
*
*
*/

void quit(char **tokenized_command)
{
	int num_token = 0, arg;

	for (; tokenized_command[num_token] != NULL; num_token++)
		;
	if (num_token == 1)
	{
		free(tokenized_command);
		free(user_inp);
		free(inp_data);
		exit(state);
	}
	else if (num_token == 2)
	{
		arg = _atoi(tokenized_command[1]);
		if (arg == -1)
		{
			print(name, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(tokenized_command[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			state = 2;
		}
		else
		{
			free(user_inp);
			free(tokenized_command);
			free(inp_data);
			exit(arg);
		}
	}
	else
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
