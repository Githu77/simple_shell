#include "main.h"
#include <stdlib.h>

/**
*_strtok_r - creates tokens
*@str: string in question
*@delimeter: delimeter to tokenize
*@s_ptr: pointer to track tokens
*Return: next token
*
*
*
*/

char *_strtok_r(char *str, char *delimeter, char **s_ptr)
{
	char *f;

	if (str == NULL)
		str = *s_ptr;

	if (*str == '\0')
	{
		*s_ptr = str;
		return (NULL);
	}

	str += _strspn(str, delimeter);
	if (*str == '\0')
	{
		*s_ptr = str;
		return (NULL);
	}

	f = str + _strcspn(str, delimeter);
	if (*f == '\0')
	{
		*s_ptr = f;
		return (str);
	}

	*f = '\0';
	*s_ptr = f + 1;
	return (str);
}

/**
* handle_signal - handles signal
* @num: number
* Return: void
*
*
*
*
*/
void handle_signal(int num)
{
	if (num == SIGINT)
		print("\n($) ", STDIN_FILENO);
}

/**
* delete_comm - removes anything after "#"
* @input: input
*
*
*
*
*
*/
void delete_comm(char *input)
{
	int x = 0;

	if (input[x] == '#')
		input[x] = '\0';
	while (input[x] != '\0')
	{
		if (input[x] == '#' && input[x - 1] == ' ')
			break;
		x++;
	}
	input[x] = '\0';
}

/**
* _atoi - string to integer
* @s: string
* Return: int
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
* @ptr: pointer to previous location
* @size1: size of ptr
* @size2: size of the new memory to be allocated
* Return: pointer to address
*
*
*
*
*
*/
void *_realloc(void *ptr, unsigned int size1, unsigned int size2)
{
	void *t_block;
	unsigned int x;

	if (ptr == NULL)
	{
		t_block = malloc(size2);
		return (t_block);
	}
	else if (size2 == size1)
		return (ptr);
	else if (size2 == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		t_block = malloc(size2);
		if (t_block != NULL)
		{
			for (x = 0; x < min(size1, size2); x++)
				*((char *)t_block + x) = *((char *)ptr + x);
			free(ptr);
			return (t_block);
		}
		else
			return (NULL);

	}
}
