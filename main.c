#include "main.h"
#include <stdlib.h>
/**
*ourShell - main function
*@argc: arguments number
*@argv: arguments array
*Return: 0
*
*
*
*
*
*
*/

int state  = 0;
char *user_inp = NULL;
char **inp_data = NULL;
char *name = NULL;

int ourShell(int argc __attribute__((unused)), char** argv)
{	
	size_t y = 0;
	int inp_type = 0;
	int x;
	char **this_inp = NULL;

	signal(SIGINT, handle_signal);
	name = argv[0];

	while (1)
	{
		handle_no_input();
		print(" ($) ", STDOUT_FILENO);

		if (getline(&user_inp, &y, stdin) == -1)
		{
			free(user_inp);
			exit(state);
		}
		delete_inp(user_inp);
		delete_comm(user_inp);
		inp_data = create_tokens(user_inp, ",");

		for (x = 0; inp_data[x] != NULL; x++)
		{
			this_inp = create_tokens(inp_data[x], " ");
			if (this_inp[0] == NULL)
			{
				free(this_inp);
				break;
			}
			inp_type = identify_inp(this_inp[0]);
			start(this_inp, inp_type);
			free(this_inp);
		}
		free(inp_data);
	}
	free(user_inp);
	return (state);
}