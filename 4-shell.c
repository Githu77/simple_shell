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
    while (*str != '\0')
    {
        if (*str == ch)
            return ((char *)str);
        str++;
    }

    if (ch == '\0')
        return ((char *)str);

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
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }

    return (*str1 - *str2);
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

size_t _strspn(const char *str, const char *accept)
{
    size_t length = 0;
    int is_match = 1;
    const char *accept_ptr;

    while (*str != '\0')
    {
        is_match = 0;
        for (accept_ptr = accept; *accept_ptr != '\0'; accept_ptr++)
        {
            if (*str == *accept_ptr)
            {
                is_match = 1;
                break;
            }
        }

        if (is_match == 0)
            return (length);

        str++;
        length++;
    }

    return (length);
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
