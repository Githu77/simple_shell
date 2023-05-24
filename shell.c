#include "main.h"

/**
*ourShell - main function
*@argc: arguments number
*@argv: arguments array
*Return: 0
*
*
*
*
*
*
*/


int main(int argc __attribute__((unused)), char **argv) {
    char **custom_commands = NULL;
    char *custom_line = NULL;
    char *custom_shell_name = NULL;
    int custom_status = 0;
    size_t custom_n = 0;

    // Assign shell name from command-line arguments
    custom_shell_name = argv[0];

    while (1) {
        custom_non_interactive();
        custom_print(" ($) ", 1); // Use file descriptor 1 for STDOUT

        if (custom_getline(&custom_line, &custom_n) == -1) {
            custom_free(custom_line);
            custom_exit(custom_status);
        }

        custom_remove_newline(custom_line);
        custom_remove_comment(custom_line);
        custom_commands = custom_tokenizer(custom_line, ";");

        for (int custom_i = 0; custom_commands[custom_i] != NULL; custom_i++) {
            char **custom_current_command = custom_tokenizer(custom_commands[custom_i], " ");

            if (custom_current_command[0] == NULL) {
                custom_free(custom_current_command);
                break;
            }

            int custom_type_command = custom_parse_command(custom_current_command[0]);

            custom_initializer(custom_current_command, custom_type_command);
            custom_free(custom_current_command);
        }

        custom_free(custom_commands);
    }

    custom_free(custom_line);
    return custom_status;
}

