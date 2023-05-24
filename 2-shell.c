#include "shell.h"

/**
* tokenizer - tokenizes input
*@input_string: input
*@delim: delimiter
*Return: tokens
*
*
*
*
*
*
*/
char **tokenizer(char *input_string, char *delim)
{
	int delim_n = 0;
	char **av = NULL;
	char *tk = NULL;
	char *s_ptr = NULL;

	tk = _strtok_r(input_string, delim, &s_ptr);

	while (tk != NULL)
	{
		av = _realloc(av, sizeof(*av) * delim_n, sizeof(*av) * (delim_n + 1));
		av[delim_n] = tk;
		tk = _strtok_r(NULL, delim, &s_ptr);
		delim_n++;
	}

	av = _realloc(av, sizeof(*av) * delim_n, sizeof(*av) * (delim_n + 1));
	av[delim_n] = NULL;

	return (av);
}

/**
*print - writes
*@stri: string
*@stre: stream
*
*
*
*
*
*
*/
void print(char *stri, int stre)
{
	int x = 0;

	for (; stri[x] != '\0'; x++)
		write(stre, &stri[x], 1);
}

/**
*remove_newline - deletes new line from a string
*@str: string
*
*
*
*
*
*
*
*/

void remove_newline(char *str)
{
	int x = 0;

	while (str[x] != '\0')
	{
		if (str[x] == '\n')
			break;
		x++;
	}
	str[x] = '\0';
}

/**
*_strcpy - copies string
*@src: source
*@dst: destination
*
*
*
*
*
*
*/

void _strcpy(char *src, char *dst)
{
	int x = 0;

	for (; src[x] != '\0'; x++)
		dst[x] = src[x];
	dst[x] = '\0';
}

/**
*_strlen - counts
*@str: string
*
*
*
*
*
*
*/
int _strlen(char *str)
{
	int l= 0;

	if (str == NULL)
		return (l);
	for (; str[l] != '\0'; l++)
		;
	return (l);
}
