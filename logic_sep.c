#include "gosh.h"

int _logical_ops(char *comd, char **currcmd)
   {
        char *command = strdup(comd), *token = strtok(command, " "),
	   *prev_command = NULL, **cmdlinev, *temp; 
        int ret = 0;

        while (token != NULL) {
                if (strcmp(token, ";") == 0 || strcmp(token, "&&") == 0 || strcmp(token, "||") == 0)
                {
                        if (prev_command != NULL)
                        {
				cmdlinev = get_args(pre_command);
				if (!cmdlinev)
					return (-1);
				*currcmd = cmdlinev[0];
                                ret = gcmd_exec(cmdlinev);
                                if (strcmp(token, "&&") == 0 && ret != 0)
                                            prev_command = NULL; break;
                                else if (strcmp(token, "||") == 0 && ret == 0)
                                              prev_command = NULL; break;
                        }
                        prev_command = NULL;
                }
                else
                {
                        if (prev_command == NULL)
                                prev_command = strdup(token);
                        else
                        {
                                temp = malloc(strlen(prev_command) + 
					strlen(token) + 2);
                                strcpy(temp, prev_command), strcat(temp, " ");
                                strcat(temp, token), free(prev_command);
                                prev_command = temp;
                        }
                }
                token = strtok(NULL, " ");
        }
        if (prev_command != NULL)
        {
		cmdlinev = get_args(pre_command);
                ret = gcmd_exec(cmdlinev);
        }
        return (ret);
}