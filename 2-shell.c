#include "main.h"
#include <stdlib.h>

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

int identify_inp(char *input)
{
	int x;
	char *int_input[] = {"env", "exit", NULL};
	char *path = NULL;

	for (x = 0; input[x] != '\0'; x++)
	{
		if (input[x] == '/')
			return (INPUT);
	}
	for (x = 0; int_input[x] != NULL; x++)
	{
		if (_strcmp(input, int_input[x]) == 0)
			return (IN_INPUT);
	}

	path = path_inp(input);
	if (path != NULL)
	{
		free(path);
		return (INPUT_PATH);
	}

	return (INV_INPUT);
}

/**
*create_tokens - format tokens into array
*@inputt: input used
*@delimiter: character to tokenize
*Return: array
*
*
*
*
*
*
*/
char **create_tokens(char *inputt, char *delimeter)
{
	int delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *s_ptr = NULL;

	token = _strtok_r(inputt, delimeter, &s_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * delim, sizeof(*av) * (delim + 1));
		av[delim] = token;
		token = _strtok_r(NULL, delimeter, &s_ptr);
		delim++;
	}

	av = _realloc(av, sizeof(*av) * delim, sizeof(*av) * (delim + 1));
	av[delim] = NULL;

	return (av);
}
