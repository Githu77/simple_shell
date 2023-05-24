#include "shell.h"

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

char **inp_data = NULL;
char *user_inp = NULL;
char *name = NULL;
int state = 0;



int main(int argc __attribute__((unused)), char **argv)
{
	char **this_inp = NULL;
	int i, inp_type = 0;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);
	name = argv[0];
	while (1)
	{
		non_interactive();
		print(" ($) ", STDOUT_FILENO);
		if (getline(&user_inp, &n, stdin) == -1)
		{
			free(user_inp);
			exit(state);
		}
			remove_newline(user_inp);
			remove_comment(user_inp);
			inp_data = tokenizer(user_inp, ";");

		for (i = 0; inp_data[i] != NULL; i++)
		{
			this_inp = tokenizer(inp_data[i], " ");
			if (this_inp[0] == NULL)
			{
				free(this_inp);
				break;
			}
			inp_type = parse_command(this_inp[0]);

			initializer(this_inp, inp_type);
			free(this_inp);
		}
		free(inp_data);
	}
	free(user_inp);

	return (state);
}

	
