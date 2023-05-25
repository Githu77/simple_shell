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

