#include "main.h"


	char **user_inp = NULL;
	char *user_inp = NULL;
	char *name = NULL;
	int state = 0;

/**
*main - main function
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


int main(int argc __attribute__((unused)), char **argv)
{
	char **this_inp = NULL;
	int i, inp_type = 0;
	size_t n = 0;

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
		inp_data = create_tokens(user_inp, ";");

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

	
