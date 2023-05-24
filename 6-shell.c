#include "shell.h"

/**
 * non_interactive - handles non_interactive mode
 *
 * Return: void
 */

void handle_no_input(void)
{
	char **this_inp = NULL;
	int j, inp_type = 0;
	size_t x = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&user_inp, &x, stdin) != -1)
		{
			delete_inp(user_inp);
			delete_comm(user_inp);
			inp_data = create_tokens(user_inp, ";");
			for (j = 0; inp_data[j] != NULL; j++)
			{
				this_inp = create_tokens(inp_data[j], " ");
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
		exit(state);
	}
}
