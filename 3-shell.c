#include "shell.h"

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

int _strcmp(char *str1, char *str2)
{
	int x = 0;

	while (str1[x] != '\0')
	{
		if (str1[x] != str2[x])
			break;
		x++;
	}
	return (str1[x] - str2[x]);
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
*_strspn - length of first string
*@str: string to check
*@accept: string to use
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
	int c = 0;

	while (str1[x] != '\0')
	{
		if (_strchr(str2, str1[x]) == NULL)
			break;
		c++;
		x++;
	}
	return (c);
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
	int l = 0, x;

	for (x = 0; str1[x] != '\0'; x++)
	{
		if (_strchr(str2, str1[x]) != NULL)
			break;
		l++;
	}
	return (l);
}













/**
*_strchr - search for char
*@s: string in question
*@c: char in question
*Return: position or NULL
*
*
*
*
*
*/


char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}
