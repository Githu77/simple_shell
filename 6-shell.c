#include "shell.h"

/**
* non_interactive - handles non_input
*
*
*
*
*
*
 */

void handle_no_input(void)
{
	char **cc = NULL;
	int i, tc = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&user_inp, &n, stdin) != -1)
		{
			delete_nl(user_inp);
			delete_comm(user_inp);
			inp_data = create_tokens(user_inp, ";");
			for (i = 0; inp_data[i] != NULL; i++)
			{
				cc = create_tokens(inp_data[i], " ");
				if (cc[0] == NULL)
				{
					free(cc);
					break;
				}
				tc = parse_command(cc[0]);
				start(cc, tc);
				free(cc);
			}
			free(inp_data);
		}
		free(user_inp);
		exit(state);
	}
}
