#include "shell.h"

/**
*parse_command - checks command type
*@command: string to be identified
*Return: type of input
*
*
*
*
*
*
*
*/

int identify_inp(char *inp)
{
	int x;
	char *inter_inp[] = {"env", "exit", NULL};
	char *path = NULL;

	for (x = 0; inp[x] != '\0'; x++)
	{
		if (inp[x] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (x = 0; inter_inp[x] != NULL; x++)
	{
		if (_strcmp(inp, inter_inp[x]) == 0)
			return (INTERNAL_COMMAND);
	}

	path = check_path(inp);
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}

	return (INVALID_COMMAND);
}

/**
*execute_command - executes inputs
*@tokenized_command: required input form
*@command_type: the type
*
*
*
*
*
*
*
*/
void run_inp(char **tc, int inp_type)
{
	void (*func)(char **command);

	if (inp_type == EXTERNAL_COMMAND)
	{
		if (execve(tc[0], tc, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (inp_type == PATH_COMMAND)
	{
		if (execve(check_path(tc[0]), tc, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (inp_type == INTERNAL_COMMAND)
	{
		func = get_function(tc[0]);
		func(tc);
	}
	if (inp_type == INVALID_COMMAND)
	{
		print(name, STDERR_FILENO);
		print(": 1: ", STDERR_FILENO);
		print(tc[0], STDERR_FILENO);
		print(": not found\n", STDERR_FILENO);
		state = 127;
	}
}

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
*_getenv - gets values
*@names: variable names
*Return: NULL or string
*
*
*
*
*
*
*/
char *_getenv(char *names)
{
	char **my_environ;
	char *p_ptr;
	char *n_cpy;

	for (my_environ = environ; *my_environ != NULL; my_environ++)
	{
		for (p_ptr = *my_environ, n_cpy = names;
		     *p_ptr == *n_cpy; p_ptr++, n_cpy++)
		{
			if (*p_ptr == '=')
				break;
		}
		if ((*p_ptr == '=') && (*n_cpy == '\0'))
			return (p_ptr + 1);
	}
	return (NULL);
}

