#include "gosh.h"
/**
 * echo_echo - gets the value of the inputed systems variable.
 * @gcmd: variable name entered by User.
 * Return: value of the environ variable
 */

int echo_echo(char **agv)
{
	int i = 1, res;
	char *env_val;
	extern int func_ret;
	
	res = func_ret;
	if (!agv || !agv[1])
		return (-1);
	while (agv[i])
	{
		if (agv[i][0] == '$' && agv[i][1] == '$')
			gosh_printf("%d", getpid());
		else if (agv[i][0] == '$' && agv[i][1] == '?')
			gosh_printf("%d", res);
		else if (agv[i][0] == '$')
		{
			env_val = _get_env(++(agv[i])), (agv[i])--;
			if (env_val)
				gosh_printf("%s", env_val);
		}
		else 
			gosh_printf("%s", agv[i]);
		i++;
		if (agv[i])
			gosh_printf(" ");
		else
			gosh_printf(" \n");
	}
	return (0);
}

