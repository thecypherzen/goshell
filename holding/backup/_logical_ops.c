#include "gosh.h"

int _logical_ops(char *comd, char **currcmd)
{
	char *command = s_dup(comd), *token,
	*prev_command = NULL, **cmdlinev, **tokensv, *temp = NULL; 
	int ret = 0, n = 0;

	printf("\n..... _logical_ops .....\n");
	tokensv = make_vectr(command, " ");
	if (!tokensv)
		return (-1);
	n = 0;
        while (token = tokensv[n])
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
			}
			if ((strcmp(token, "&&") == 0 && ret != 0) 
				|| (strcmp(token, "||") == 0 
				&& ret == 0))
			{
				prev_command = NULL;
				break;
			}
			else
			{
				printf("c_token: %s\n", token);
				token = tokensv[++n];
				printf("n_token: %s\n", token);
				prev_command = token;
				/*printf("next cmd: %s\n", 
					prev_command);*/
			}
                }
                else
                {
                        if (!prev_command && token)
			{
				printf("\nduppn token to prev_cmd\n");
                                prev_command = s_dup(token);
			}
                        else if (prev_command && token)
                        {
				printf("both prev & token not null\n");
				ret = s_len(prev_command) + s_len(token) + 2;
				printf("ret: %d\n", ret);
                                temp = (char *)malloc(ret);
				printf("Malloc successful\n");
                                strcpy(temp, prev_command);
				strcat(temp, " "), free(prev_command);
                                strcat(temp, token), prev_command = NULL;
                                prev_command = s_dup(temp);
				free(temp);
				/*printf("temp: %s\n", temp);*/
				printf("prev_cmd: %s\n", prev_command);
                        }
			else
				break;
                }
                n++;
        }
        if (prev_command && !token)
        {
		printf("finally: %s\n", prev_command);
		cmdlinev = get_args(prev_command);
		*currcmd = cmdlinev[0];
                ret = gcmd_exec(cmdlinev);
        }
        return (ret);
}