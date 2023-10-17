#include "gosh.h"

/**
*
*/

char *_get_env(char **agv)
{
	/* get the length of variable passed*/

	int len_var = s_len(*agv);
	char **env_address = environ, **agv_value;

	while (*env_address)
		{
			if (strncmp(agv, *env_address, len_var) == 0 && *env_address[len_var] == '=')
			{
				return (&(*env_address)[len_var + 1]);
			}

			(*env_address)++;
		}
	return (NULL);
}
