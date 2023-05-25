#include "shell.h"


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
char *check_path(char *inp)
{
	char **p_array = NULL;
	char *t, *t2, *p_cpy;
	char *path = _getenv("PATH");
	int x;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	p_cpy = malloc(sizeof(*p_cpy) * (_strlen(path) + 1));
	_strcpy(path, p_cpy);
	p_array = create_tokens(p_cpy, ":");
	for (x = 0; p_array[x] != NULL; x++)
	{
		t2 = _strcat(p_array[x], "/");
		t = _strcat(t2, inp);
		if (access(t, F_OK) == 0)
		{
			free(t2);
			free(p_array);
			free(p_cpy);
			return (t);
		}
		free(t);
		free(t2);
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
void (*get_function(char *inp))(char **)
{
	int x;
	function_map mapping[] = {
		{"env", env}, {"exit", quit}
	};

	for (x = 0; x < 2; x++)
	{
		if (_strcmp(inp, mapping[x].command_name) == 0)
			return (mapping[x].function);
	}
	return (NULL);
}
