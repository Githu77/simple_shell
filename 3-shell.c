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


void print(const char *str, int fd)
{
const char *ptr = str;

while (*ptr != '\0')
{
write(fd, ptr, 1);
ptr++;
}
}

/**
*delete_inp - removes the new line
*@str: string
*
*
*
*
*
*/

void delete_inp(char *str)
{
char *ptr = str;

while (*ptr != '\0')
{
if (*ptr == '\n')
{
*ptr = '\0';
break;
}
ptr++;
}
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

void _strcpy(char *dest, const char *src)
{
char *ptr_dest = dest;

while (*src != '\0')
{
*ptr_dest = *src;
ptr_dest++;
src++;
}

*ptr_dest = '\0';
}


/**
*_strlen - checks string length
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

size_t _strlen(const char *str)
{
const char *ptr = str;
size_t length = 0;

while (*ptr != '\0')
{
length++;
ptr++;
}

return (length);
}

