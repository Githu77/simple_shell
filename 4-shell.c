#include "main.h"
#include <stdlib.h>

/**
*_strchr - search for char
*@str: string in question
*@ch: char in question
*Return: position or NULL
*
*
*
*
*
*/

char *_strchr(const char *str, int ch)
{
	int x = 0;

	for (; str[x] != ch && str[x] != '\0'; x++)
		;
	if (str[x] == ch)
		return (str + x);
	else
		return (NULL);
}

/**
*_strcmp - compares strings
*@str1: first sttring
*@str2: second string
*Return: difference
*
*
*
*
*
*
*/

int _strcmp(const char *str1, const char *str2)
{
    int x = 0;

	while (str1[x] != '\0')
	{
		if (str1[x] != str1[x])
			break;
		x++;
	}
	return (str1[i] - str2[i]);
}

/**
*_strspn - length of first string
*@str1: string to check
*@str2: string to use
*Return: bytes numbers
*
*
*
*
*
*/

int _strspn(char *str1, char *str2)
{
	int x = 0;
	int match = 0;

	while (str1[x] != '\0')
	{
		if (_strchr(str2, str1[x]) == NULL)
			break;
		match++;
		x++;
	}
	return (match);
}

/**
*_strcat - joins two strings
*@dest: string to join to
*@src: string to add
*Return: pointer to new string
*
*
*
*
*
*
*/

char *_strcat(char *dest, char *src)
{
	char *n_string =  NULL;
	int l_dest = _strlen(dest);
	int l_source = _strlen(src);

	n_string = malloc(sizeof(*n_string) * (l_dest + l_source + 1));
	_strcpy(dest, n_string);
	_strcpy(src, n_string + l_dest);
	n_string[l_dest + l_source] = '\0';
	return (n_string);
}

/**
*_strcspn - checks unique characters in str1
*@str1: string to be searched
*@str2: string to be used
*Return: index at which a char in str1 exists in str2
*
*
*
*
*
 */


int _strcspn(char *str1, char *str2)
{
	int l = 0, i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (_strchr(str2, str1[i]) != NULL)
			break;
		l++;
	}
	return (l);
}
