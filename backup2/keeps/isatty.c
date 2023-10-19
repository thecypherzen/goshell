#include "gosh.h"

/**
* gosh_isatty - a function that implements the
* non-interactive shell mode
* @filename: the filename conctaining all the cmds to be executed
* Return: 0 on success, -1 on error.
*/

void gosh_isatty(const char *filename) 
{
    FILE *g_file = fopen(filename, "r");
    if (g_file == NULL) 
    {
        perror("Failed to open file");
        return;
    }

    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, g_file) != -1) 
    {
        if (line[strlen(line) - 1] == '\n') 
	{
            line[strlen(line) - 1] = '\0';
        }
       **** execute_command(line); ****
    }

    free(line);
    fclose(g_file);
}

/**
* main - a function that implements the
* non-interactive shell mode
* @agc: number of arguments
* @agv: the filename conctaining all the cmds to be executed
* Return: 0 on success, -1 on error.
*/

int main(int agc, char *agv[])
{
	if (isatty(STDIN_FILENO)) 
	{
        /* Interactive mode: stdin is connected to a terminal if isatty returns a non zero value*/
        printf("Interactive mode\n");
		 /****GOSH_execute_command(line);****/
    	}
	else
	{
        /* Non-interactive mode: stdin is not connected to a terminal if isatty returns 0 */
        printf("Non-interactive mode\n");
		/****ISATTY_execute_command(line);****/
	}

	

    if (a gc > 1)
    {
        /*Filename provided, execute commands from the file */
        *** execute_commands_from_file(agv[1]); ***
    }
    else
    {
        /* Interactive mode, print prompt and read from stdin*/
        interactive_shell();
    }

    return 0;
}
