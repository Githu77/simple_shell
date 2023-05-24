#include "main.h"
#include <stdlib.h>

/**
* quit - stops shell
* @tokenized_inp: input
*
*
*
*
*
*
*
*/

void quit(char **tokenized_inp)
{
	int nt = 0, arg;

	for (; tokenized_inp[nt] != NULL; nt++)
		;
	if (nt == 1)
	{
		free(tokenized_inp);
		free(user_inp);
		free(inp_data);
		exit(state);
	}
	else if (nt == 2)
	{
		arg = _atoi(tokenized_inp[1]);
		if (arg == -1)
		{
			print(name, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(tokenized_inp[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			state = 2;
		}
		else
		{
			free(user_inp);
			free(tokenized_inp);
			free(inp_data);
			exit(arg);
		}
	}
	else
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}

/**
*env - prints environment
*@tokenized_inp: input
*
*
*
*
*
*
*
*/

void env(char **tokenized_inp __attribute__((unused)))
{
	int x;

	for (x = 0; environment[x] != NULL; x++)
	{
		print(environment[x], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

