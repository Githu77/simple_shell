#include "shell.h"


/**
*_strtok_r - tokenize
*@str: string
*@delimeter: delimeter
*@s_ptr: pointer
*Return: token
*
*
*
*
*
*
*
*
*
*/
char *_strtok_r(char *string, char *delim, char **save_ptr)
{
	char *finish;

	if (string == NULL)
		string = *save_ptr;

	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	string += _strspn(string, delim);
	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	finish = string + _strcspn(string, delim);
	if (*finish == '\0')
	{
		*save_ptr = finish;
		return (string);
	}

	*finish = '\0';
	*save_ptr = finish + 1;
	return (string);
}

/**
* _atoi - string - integer
* @s: string
* Return: integer
*
*
*
*
*
*
*/
int _atoi(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
			return (-1);
		else if ((*s < '0' || *s > '9') && *s != '\0')
			return (-1);
		else if (*s >= '0'  && *s <= '9')
			n = (n * 10) + (*s - '0');
		else if (n > 0)
			break;
	} while (*s++);
	return (n);
}

/**
* _realloc - reallocates memory
* @ptr: location
* @size1: pointer size
* @size2: new size
* Return: pointer
*
*
*
*
*
*
*
*
*
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp_block;
	unsigned int i;

	if (ptr == NULL)
	{
		temp_block = malloc(new_size);
		return (temp_block);
	}
	else if (new_size == old_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp_block = malloc(new_size);
		if (temp_block != NULL)
		{
			for (i = 0; i < min(old_size, new_size); i++)
				*((char *)temp_block + i) = *((char *)ptr + i);
			free(ptr);
			return (temp_block);
		}
		else
			return (NULL);

	}
}

/**
 * ctrl_c_handler - handles the signal raised by CTRL-C
 * @signum: signal number
 *
 * Return: void
 */
void ctrl_c_handler(int signum)
{
	if (signum == SIGINT)
		print("\n($) ", STDIN_FILENO);
}

/**
* remove_comment - delete comment
* @input: input
*
*
*
*
*
*/
void remove_comment(char *input)
{
	int i = 0;

	if (input[i] == '#')
		input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
			break;
		i++;
	}
	input[i] = '\0';
}


