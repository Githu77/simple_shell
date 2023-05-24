#include "shell.h"

/**
 * non_interactive - handles non_interactive mode
 *
 * Return: void
 */

void non_interactive(void)
{
	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&user_inp, &n, stdin) != -1)
		{
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
		exit(status);
	}
}
