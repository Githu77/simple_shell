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

void start(char **this_inp, int type_command)
{
	pid_t PID;

	if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			execute_command(this_inp, type_command);
		else
		{
			waitpid(PID, &state, 0);
			state >>= 8;
		}
	}
	else
		execute_command(this_inp, type_command);
}
