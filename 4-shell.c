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
	char *f;

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

	f = string + _strcspn(string, delim);
	if (*f == '\0')
	{
		*save_ptr = f;
		return (string);
	}

	*f = '\0';
	*save_ptr = f + 1;
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
	unsigned int x = 0;

	do {
		if (*s == '-')
			return (-1);
		else if ((*s < '0' || *s > '9') && *s != '\0')
			return (-1);
		else if (*s >= '0'  && *s <= '9')
			x = (x * 10) + (*s - '0');
		else if (x > 0)
			break;
	} while (*s++);
	return (x);
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
void *_realloc(void *p, unsigned int size1, unsigned int size2)
{
	void *t_block;
	unsigned int x;

	if (p == NULL)
	{
		t_block = malloc(size2);
		return (t_block);
	}
	else if (size2 == size1)
		return (p);
	else if (size2 == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}
	else
	{
		t_block = malloc(size2);
		if (t_block != NULL)
		{
			for (x = 0; x < min(size1, size2); x++)
				*((char *)t_block + x) = *((char *)p + x);
			free(p);
			return (t_block);
		}
		else
			return (NULL);

	}
}

/**
* ctrl_c_handler - handles signal
* @signum: signal 
*
*
*
*
*
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
void delete_comm(char *inp)
{
	int x = 0;

	if (inp[x] == '#')
		inp[x] = '\0';
	while (inp[x] != '\0')
	{
		if (inp[x] == '#' && inp[x - 1] == ' ')
			break;
		x++;
	}
	inp[x] = '\0';
}
