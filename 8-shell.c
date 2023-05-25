#include "shell.h"

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

void delete_nl(char *str)
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

