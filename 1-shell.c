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
	int x;

	for (x = 0; environ[x] != NULL; x++)
	{
		print(environ[x], STDOUT_FILENO);
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
	int n_token = 0, args;

	for (; tokenized_command[n_token] != NULL; n_token++)
		;
	if (n_token == 1)
	{
		free(tokenized_command);
		free(user_inp);
		free(inp_data);
		exit(state);
	}
	else if (n_token == 2)
	{
		args = _atoi(tokenized_command[1]);
		if (args == -1)
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
			exit(args);
		}
	}
	else
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
