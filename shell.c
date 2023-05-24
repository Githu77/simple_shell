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
	char **current_command = NULL;
	int i, type_command = 0;
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
			current_command = tokenizer(inp_data[i], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			type_command = parse_command(current_command[0]);

			initializer(current_command, type_command);
			free(current_command);
		}
		free(inp_data);
	}
	free(user_inp);

	return (state);
}

	
