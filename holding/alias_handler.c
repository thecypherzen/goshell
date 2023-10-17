#include "gosh.h"
/**
 * alias_handler - controls execution of alias commands
 * @agv: arguments vector from user
 * Return: 0 on success, -1 on error.
 */
int alias_handler(char **agv)
{
	int i = 1, ret;
	char *temp, *name, *val, *entry;
	struct alias *found;

	if (!agv[1])
	{
		return (gosh_print_aliases());
	}
	else
	{
		while (agv[i])
		{
			entry = s_dup(agv[i]);
			temp = s_chr(entry, '=');
			if (temp)
			{
				name = s_tok(entry, "=");
				val = s_tok(NULL, "=");
				ret = gosh_define_alias(name, val);
				if (ret < 0)
					gosh_printf("An error occured\n");
			}
			else
			{
				found = gosh_find_alias(entry);
				if (!found)
				{
					gosh_printf("%s not found\n",
						entry);
				}
				gosh_printf("alias %s=%s\n", 
					found->a_name, found->a_value);
			}
			i++;
		}
	}
	return (0);
}
