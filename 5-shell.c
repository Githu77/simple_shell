#include "shell.h"

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
