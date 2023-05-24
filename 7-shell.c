#include "shell.h"

/**
*identify_inp - checks command type
*@inp: string to be identified
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
	char *int_inp[] = {"env", "exit", NULL};
	char *path = NULL;

	for (x = 0; inp[x] != '\0'; x++)
	{
		if (inp[x] == '/')
			return (INPUT);
	}
	for (x = 0; int_inp[x] != NULL; x++)
	{
		if (_strcmp(inp, int_inp[x]) == 0)
			return (IN_INPUT);
	}

	path = path_inp(inp);
	if (path != NULL)
	{
		free(path);
		return (INPUT_PATH);
	}

	return (INV_INPUT);
}

/**
 * execute_command - executes a command based on it's type
 * @tokenized_command: tokenized form of the command (ls -l == {ls, -l, NULL})
 * @command_type: type of the command
 *
 * Return: void
 */
void execute_command(char **tokenized_command, int command_type)
{
	void (*func)(char **command);

	if (command_type == EXTERNAL_COMMAND)
	{
		if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == PATH_COMMAND)
	{
		if (execve(check_path(tokenized_command[0]), tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == INTERNAL_COMMAND)
	{
		func = get_func(tokenized_command[0]);
		func(tokenized_command);
	}
	if (command_type == INVALID_COMMAND)
	{
		print(shell_name, STDERR_FILENO);
		print(": 1: ", STDERR_FILENO);
		print(tokenized_command[0], STDERR_FILENO);
		print(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * check_path - checks if a command is found in the PATH
 * @command: command to be used
 *
 * Return: path where the command is found in, NULL if not found
 */
char *check_path(char *command)
{
	char **path_array = NULL;
	char *temp, *temp2, *path_cpy;
	char *path = _getenv("PATH");
	int i;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));
	_strcpy(path, path_cpy);
	path_array = tokenizer(path_cpy, ":");
	for (i = 0; path_array[i] != NULL; i++)
	{
		temp2 = _strcat(path_array[i], "/");
		temp = _strcat(temp2, command);
		if (access(temp, F_OK) == 0)
		{
			free(temp2);
			free(path_array);
			free(path_cpy);
			return (temp);
		}
		free(temp);
		free(temp2);
	}
	free(path_cpy);
	free(path_array);
	return (NULL);
}

/**
 * get_func - retrieves a function based on the command given and a mapping
 * @command: string to check against the mapping
 *
 * Return: pointer to the proper function, or null on fail
 */
void (*get_func(char *command))(char **)
{
	int i;
	function_map mapping[] = {
		{"env", env}, {"exit", quit}
	};

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(command, mapping[i].command_name) == 0)
			return (mapping[i].func);
	}
	return (NULL);
}

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: the value of the variable as a string
 */
char *_getenv(char *name)
{
	char **my_environ;
	char *pair_ptr;
	char *name_cpy;

	for (my_environ = environ; *my_environ != NULL; my_environ++)
	{
		for (pair_ptr = *my_environ, name_cpy = name;
		     *pair_ptr == *name_cpy; pair_ptr++, name_cpy++)
		{
			if (*pair_ptr == '=')
				break;
		}
		if ((*pair_ptr == '=') && (*name_cpy == '\0'))
			return (pair_ptr + 1);
	}
	return (NULL);
}

