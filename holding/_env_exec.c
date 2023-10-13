#include "gosh.h"
/*
 * exec_env - executes the env command
 * return: total chars printed.
*/

int _env_exec(char **agv)
{
	int n;
	char **env = environ;
	
	if (agv[1])
		return (-1);
	
	while (*env != NULL)
	{
		n = s_put(*env), env++;
		if (n < 0)
			return (-1);
	}
	n = s_write('\n');
	if (n < 1)
		return (-1);
	return (0);
}