#include "gosh.h"
/*
 * gcmd_exec - handles command selection and execution
 * @agv: arguments vector
 * Return: 0 on success, -1 on error
*/
int gcmd_exec(char **agv)
{
	char *s_cmds[] = { "exit", "env", "setenv",
				"unsetenv", NULL}, *path_name;
	int j = 0, i = 0, match = 0;
	do
	{
		j = 0;
		while (s_cmds[j++])
		{
			if (strcmp(agv[i], s_cmds[j - 1]) == 0)
			{
				match = 1;
				break;
			}
		}
		if (match)
			break;
	}while (++i < 1);
	if (match)
	{
		switch (j)
		{
			case 1:
				_exit_exec(agv);
				break;
			case 2:
				return (_env_exec(agv));
			case 3:
				return (_setenv_exec(agv));
				break;
			case 4:
				return (_unsetenv_exec(agv));
				break;
			default:
				return (-1);
				break;
		}
	}
	else
	{
		/* Ex ecute other commands */
		printf("Preparing to fork\n");
		path_name = get_gcmdpath(agv);
		if (!path_name)
			printf("gcmd_exec: PATH_NAME = null\n");
		else
			printf("IN gcmd_exec: PATH_NAME = %s\n", 
				path_name);
	}
	return (0);
}