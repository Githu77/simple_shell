#include "main.h"

/**
*print - prins to stdout
*@str: to print
*@fd: where to print to
*
*
*
*
*/


void print(char *str, int fd)
{
	int x = 0;

	for (; str[x] != '\0'; x++)
		write(fd, &str[x], 1);
}

/**
*remove_newline - removes the new line
*@str: string
*
*
*
*
*
*/

void delete_inp(char *str)
{
	int  = 0;

	while (str[x] != '\0')
	{
		if (str[x] == '\n')
			break;
		x++;
	}
	str[x] = '\0';
}


/**
*_strcpy - copies string to another
*@dest: destination
*@src: source
*
*
*
*
*
*
*
*
*/

void _strcpy(char *dest, const *src)
{
	int x = 0;

	for (; src[x] != '\0'; x++)
		dest[x] = src[x];
	dest[x] = '\0';
}


/**
*my_strlen - checks string length
*@str: string in question
*Return: length
*
*
*
*
*
*
*
*/

int _strlen(char *str)
{
    int x = 0;

	if (str == NULL)
		return (x);
	for (; str[x] != '\0'; x++)
		;
	return (x);
}

