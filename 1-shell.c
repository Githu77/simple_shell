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

void env(char **t_inp __attribute__((unused)))
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
* @t_inp: command
*
*
*
*
*
*
*/

void quit(char **t_inp)
{
	int n_token = 0, args;

	for (; t_inp[n_token] != NULL; n_token++)
		;
	if (n_token == 1)
	{
		free(t_inp);
		free(user_inp);
		free(inp_data);
		exit(state);
	}
	else if (n_token == 2)
	{
		args = _atoi(t_inp[1]);
		if (args == -1)
		{
			print(name, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(t_inp[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			state = 2;
		}
		else
		{
			free(user_inp);
			free(t_inp);
			free(inp_data);
			exit(args);
		}
	}
	else
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
