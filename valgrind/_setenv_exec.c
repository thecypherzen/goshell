#include "gosh.h"
/**
 * _setenv_exec - executes the setenv command
 * @agv: arguments vector
 * Return: 0 on success, -1 otherwise
*/

int _setenv_exec(char **agv)
{
	char *name = agv[1], *val = agv[2];
	int flag;
	if (agv)
	{
		printf("agv[0]: %s\n", agv[0]);
		if (agv[3] != NULL)
			flag = gosh_atoi(agv[3]);
		else
			flag = 0;
		if (!name || !val)
			return (-1);
		if (setenv(name, val, flag) != 0)
			return (-1);
	}
	return (0);
}
