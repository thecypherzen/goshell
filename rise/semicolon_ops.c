#include "gosh.h"
/* semicolon_ops - first step now will be to Split input
 * by semicolon to separate multiple commands
 * @delim: the parameter passed
 * Return: standard output depending on success
 */
char **semicolon_ops(gcmd, delim) 
{
  if (s_chr(gcmd, ";") != NULL) 
  {
    char *commands[MAX_INPUT_SIZE];
    char *token = strtok(gcmd, ";");
    int num_commands = 0;

    while (token != NULL && num_commands < MAX_INPUT_SIZE) 
    {
      /* creating an array of commands */
      commands[num_commands] = token;
      token = strtok(NULL, ";");
      num_commands++;
    }

    /* Execute each command */
    for (int i = 0; i < num_commands; i++) 
    {
      int func_ret_val = get_args(commands[i]);
    }
  }
}