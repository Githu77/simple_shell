#include "main.h"
#include <stdlib.h>


/**
*start - starts shell
*@inp_type: identifies token
*@this_inp: token in question
*
*
*
*
*
*/

void start(char **this_inp, int inp_type)
{
	pid_t PID;

	if (inp_type == INPUT || inp_type == INPUT_PATH)
	{
		PID = fork();
		if (PID == 0)
			run_inp(this_inp, inp_type);
		else
		{
			waitpid(PID, &status, 0);
			state >>= 8;
		}
	}
	else
		run_inp(this_inp, inp_type);
}

/**
*run_inp - executes inputs
*@tokenized_inp: required input form
*@type_inp: the type
*
*
*
*
*
*
*
*/

void run_inp(char **tokenized_inp, int type_inp)
{
	void (*func)(char **command);

	if (type_inp == INPUT)
	{
		if (execve(tokenized_inp[0], tokenized_inp, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (type_inp == INPUT_PATH)
	{
		if (execve(path_inp(tokenized_inp[0]), tokenized_inp, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (type_inp == IN_INP)
	{
		function = get_function(tokenized_inp[0]);
		function(tokenized_inp);
	}
	if (type_inp == INV_INP)
	{
		print(name, STDERR_FILENO);
		print(": 1: ", STDERR_FILENO);
		print(tokenized_inp[0], STDERR_FILENO);
		print(": not found\n", STDERR_FILENO);
		state = 127;
	}
}



/**
*path_inp - evaluates inputs presence in the PATH
*@input: input used
*Return: NULL
*
*
*
*
*
*
*/
char *path_inp(char *input)
{
char **paths = NULL;
char *c1, *c2, *cp_path;
char *path = _getenv("PATH");
int x;

if (path == NULL || _strlen(path) == 0)
return (NULL);
cp_path = malloc(sizeof(*cp_path) * (_strlen(path) + 1));
_strcpy(path, cp_path);
paths = create_tokens(cp_path, ":");
for (x = 0; paths[x] != NULL; x++)
{
c2 = _strcat(paths[x], "/");
c1 = _strcat(c2, input);
if (access(c1, F_OK) == 0)
{
free(c2);
free(paths);
free(cp_path);
return (c1);
}
free(c1);
free(c2);
}
free(cp_path);
free(paths);
return (NULL);
}

/**
*get_function - gets particular functions
*@inp: command entered
*Return: NULL or pointer
*
*
*
*
*
*
*
*/
void (*get_function(char *inp))(char **)
{
int x = 0;
function_map mapping[] = {
{"env", env}, {"exit", quit}
};

while (x < 2)
{
if (_strcmp(inp, mapping[x].command_name) == 0)
return (mapping[x].function);
x++;
}
return (NULL);
}


/**
*_getenv - gets values
*@names: variable names
*Return: NULL or string
*
*
*
*
*
*
*/
char *_getenv(char *names)
{
char **m_environment = environment;
char *p_ptr;
char *n_cpy;

while (*m_environment != NULL)
{
p_ptr = *m_environment;
n_cpy = names;

while (*p_ptr == *n_cpy)
{
if (*p_ptr == '=')
break;
p_ptr++;
n_cpy++;
}

if ((*p_ptr == '=') && (*n_cpy == '\0'))
return (p_ptr + 1);

m_environment++;
}

return (NULL);
}

