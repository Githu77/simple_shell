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

int parse_command(char *command)
{
	int x;
	char *inter_inp[] = {"env", "exit", NULL};
	char *path = NULL;

	for (x = 0; command[x] != '\0'; x++)
	{
		if (command[x] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (x = 0; inter_inp[x] != NULL; x++)
	{
		if (_strcmp(command, inter_inp[x]) == 0)
			return (INTERNAL_COMMAND);
	}

	path = check_path(command);
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
		print(name, STDERR_FILENO);
		print(": 1: ", STDERR_FILENO);
		print(tokenized_command[0], STDERR_FILENO);
		print(": not found\n", STDERR_FILENO);
		state = 127;
	}
}

/**
*
*check_path - evaluates inputs presence in the PATH
*@command: input used
*Return: NULL
*
*
*
*
*
*
*/
char *check_path(char *command)
{
	char **path_array = NULL;
	char *temp, *temp2, *path_cpy;
	char *path = _getenv("PATH");
	int x;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));
	_strcpy(path, path_cpy);
	path_array = tokenizer(path_cpy, ":");
	for (x = 0; path_array[x] != NULL; x++)
	{
		temp2 = _strcat(path_array[x], "/");
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
*get_func - gets particular functions
*@command: command entered
*Return: NULL or pointer
*
*
*
*
*
*
*
*/
void (*get_func(char *command))(char **)
{
	int x;
	function_map mapping[] = {
		{"env", env}, {"exit", quit}
	};

	for (x = 0; x < 2; x++)
	{
		if (_strcmp(command, mapping[x].command_name) == 0)
			return (mapping[x].func);
	}
	return (NULL);
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

