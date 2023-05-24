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
	char *inter_input[] = {"env", "exit", NULL};
	char *path = NULL;

	for (x = 0; command[x] != '\0'; x++)
	{
		if (command[x] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (x = 0; inter_input[x] != NULL; x++)
	{
		if (_strcmp(command, inter_input[x]) == 0)
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
	char **p_array = NULL;
	char *c, *c1, *p_cpy;
	char *path = _getenv("PATH");
	int x;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	p_cpy = malloc(sizeof(*p_cpy) * (_strlen(path) + 1));
	_strcpy(path, p_cpy);
	p_array = tokenizer(p_cpy, ":");
	for (x = 0; p_array[x] != NULL; x++)
	{
		c1 = _strcat(p_array[x], "/");
		c = _strcat(c1, command);
		if (access(c, F_OK) == 0)
		{
			free(c1);
			free(p_array);
			free(p_cpy);
			return (c);
		}
		free(c);
		free(c1);
	}
	free(p_cpy);
	free(p_array);
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
		if (_strcmp(command, mapping[i].command_name) == 0)
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

