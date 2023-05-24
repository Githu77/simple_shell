#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/*constants*/
#define INPUT 1
#define IN_INPUT 2
#define INPUT_PATH 3
#define INV_INPUT -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
*struct map - a struct
*@command_name: command
*@func: function
*/

typedef struct map
{
	char *command_name;
	void (*function)(char **inp);
} function_map;

extern char **environment;
extern char *user_inp;
extern char **inp_data;
extern char *name;
extern int state;

int main(int argc __attribute__((unused)), char **argv);
void start(char **this_inp, int inp_type);
void run_inp (char **tokenized_inp, int type_inp);
char *path_inp(char *input);
void (*get_function(char *inp))(char **);
char *_getenv(char *names);
int identify_inp(char *input);
char **create_tokens(char *inputt, char *delimeter);
void print(const char *str, int fd);
void delete_inp(char *str);
void _strcpy(char *dest, const *src);
int _strlen(char *str);
char *_strtok_r(char *str, char *delimeter, char **s_ptr);
void handle_signal(int num);
void delete_comm(char *input);
int _atoi(char *s);
void *_realloc(void *ptr, unsigned int size1, unsigned int size2);
char *_strchr(const char *str, int ch);
int _strcmp(const char *str1, const char *str2);
int _strspn(char *str1, char *str2);
char *_strcat(char *dest, char *src);
int _strcspn(char *str1, char *str2);
void quit(char **tokenized_inp);
void env(char **);
void handle_no_input(void);

#endif
