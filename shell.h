#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
*struct map - struct
*@inp: command
*@function: executable
*
*
*
*
*
*
*/

typedef struct map
{
	char *command_name;
	void (*function)(char **inp);
} function_map;

void delete_comm(char *);
int identify_inp(char *);
void env(char **);
void quit(char **);
extern void handle_no_input(void);
extern void start(char **this_inp, int inp_type);
void print(char *, int);
char **create_tokens(char *, char *);
void delete_nl(char *);
int _strlen(char *);
void _strcpy(char *, char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);
extern char **environ;
extern char *user_inp;
int _strcspn(char *, char *);
char *_strchr(char *, char);
char *_strtok_r(char *, char *, char **);
int _atoi(char *);
extern char **inp_data;
void print(char *, int);
char **create_tokens(char *, char *);
void delete_nl(char *);
int _strlen(char *);
extern char *name;
extern int state;
void _strcpy(char *, char *);
int _strcmp(char *, char *);
void run_inp(char **, int);
char *check_path(char *);
void (*get_function(char *))(char **);
char *_getenv(char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);
void *_realloc(void *p, unsigned int size1, unsigned int size2);
void ctrl_c_handler(int);

#endif


