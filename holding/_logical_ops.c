#include "gosh.h"

int _logical_ops(char *comd, char **currcmd)
   {
	   char *command = s_dup(comd), *token,
	   *prev_command = NULL, **cmdlinev, tokensv, *temp; 
	   int ret = 0, n = 0;

	   printf("command: %s\n", command);
	   printf("comd: %s\n", comd);
	   while (command[ret])
	   {
		   printf("%c\n", command[ret]);
		   if (command[ret] == ' ')
			   n++;
		   ret++;
	   }
	   printf("tokens: %d\n", n);
	   ret = 0;
	   token = strtok(command, " ");
	   while (token)
	   {
		   printf("Token %d: %s\n", ++ret, token);
		   token = strtok(NULL, " ");
	   }
	 /*  
	   printf("INSIDE logical ops FUNC\n");
        while (token != NULL)
	{
		printf("curr token: %s\n", token);
                if (strcmp(token, "&&") == 0 || strcmp(token, "||") == 0)
                {
                        if (prev_command != NULL)
                        {
				printf("to exec: %s\n", prev_command);
				cmdlinev = get_args(prev_command);
				if (!cmdlinev)
					return (-1);
				*currcmd = cmdlinev[0];
                                ret = gcmd_exec(cmdlinev);
				printf("\n***retval: %d***\n\n", ret);
				if ((strcmp(token, "&&") == 0 && ret != 0) ||
					(strcmp(token, "||") == 0 && ret == 0))
				{
					prev_command = NULL;
					break;
				}
				else
				{
					printf("c_token: %s\n", token);
					token = strtok(NULL, " ");
					printf("n_token: %s\n", token);
					prev_command = strdup(token);
					printf("next cmd: %s\n", prev_command);
				}
			}
                        prev_command = NULL;
                }
                else
                {
                        if (!prev_command && token)
                                prev_command = strdup(token);

                        else if (prev_command && token)
                        {
                                temp = malloc(strlen(prev_command) + 
					strlen(token) + 2);
				temp[0] = '\0';
                                strcpy(temp, prev_command), strcat(temp, " ");
                                strcat(temp, token), free(prev_command);
                                prev_command = temp;
				printf("temp: %s\n", temp);
                        }
			else
				break;
                }
                token = strtok(NULL, " ");
        }
        if (prev_command && !token)
        {
		printf("finally: %s\n", prev_command);
		cmdlinev = get_args(prev_command);
		*currcmd = cmdlinev[0];
                ret = gcmd_exec(cmdlinev);
        } */
        return (ret);
}