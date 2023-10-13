#include "gosh.h"
/**
 * _setenv_exec - executes the setenv command
 * @agv: arguments vector
 * Return: 0 on success, -1 otherwise
*/

int _setenv_exec(char **agv)
{
	char *name = agv[1], *val = agv[2];
	int flag = agv[3] ? atoi(agv[3]) : 0;

	if (!name || !val)
		return (-1);
	
	if (setenv(name, val, flag) != 0)
		return (-1);
	
	return (0);
}