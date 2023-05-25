#include "shell.h"


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
				tc = identify_inp(cc[0]);
				start(cc, tc);
				free(cc);
			}
			free(inp_data);
		}
		free(user_inp);
		exit(state);
	}
}



/**
* initializer - starts shell
* @current_command: current token
* @type_command: identify token
*
*
*
*
*
*
*/

void start(char **this_inp, int inp_type)
{
	pid_t PID;

	if (inp_type == EXTERNAL_COMMAND || inp_type == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			run_inp(this_inp, inp_type);
		else
		{
			waitpid(PID, &state, 0);
			state >>= 8;
		}
	}
	else
		run_inp(this_inp, inp_type);
}
