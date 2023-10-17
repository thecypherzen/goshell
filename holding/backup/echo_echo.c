#include "gosh.h"
/**
 * get_variable - gets the value of the inputed systems variable.
 * @gcmd: variable name entered by User.
 * Return: value of the environ variable
 */

int echo_echo(char **gcmd)
{
	int i;
	char *env_val;
	extern int func_ret;
	
	char *var_ids[] = {"$$", "$?", "$PATH", "$HOME", "$USER",
			   "$LOGNAME", "$SHELL", NULL};
	char *nest[] = {"$$", "$?", "PATH", "HOME", "USER", "LOGNAME", "SHELL", NULL};
	if (!gcmd || !gcmd[1])
		return (-1);
	if (strcmp(gcmd[1], var_ids[0]) == 0)
		printf("%d\n", getpid());
	if (strcmp(gcmd[1], var_ids[1]) == 0)
		printf("%d\n", func_ret);
	i = 2;
	while (var_ids[i]) 
	{
		if (strcmp(gcmd[1], var_ids[i]) == 0)
		{
			env_val = getenv(nest[i]);
			printf("%s\n", env_val ? env_val : "\n");
			return (env_val ? 0 : -1);
		}
		i++;
	}
	i = 1;
	while (gcmd)	
	{
		printf("%s", gcmd[i]);
		i++;
	}
	return (0);
}

