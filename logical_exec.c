#include "gosh.h"
/**
 * logical_exec - executes logical and/or operations delimited with
 * ; sequentially.
 * @gcmdln: the user-entered command from stdin
 * Return: 0 on success, -1 on failure
 */
int logical_exec(char *gcmdln)
{
	size_t cols = 0, i = 0;
	char *cmdstr, **cmdv, *cmdline, *currcmd;
	int retval, syntax_err;
	extern int func_ret;

	syntax_err = _syntax_checkr(&cmdstr, gcmdln);
	if (!syntax_err)
	{
		while (cmdstr[i])
		{
			if (cmdstr[i] == ';')
				cols++;
			i++;
		}
		cols++, i = 0;
		cmdv = malloc(sizeof(char *) * (cols + 1));
		cmdv[cols] = NULL, cmdline = strtok(cmdstr, ";");
		if (cmdline)
		{
			while (cols > 0) 
			{
				cmdv[i] = cmdline;
				cmdline = strtok(NULL, ";");
				cols--, i++;
			}
		}
		else
			cmdv[0] = strdup(cmdstr);
		for (i = 0; cmdv[i]; i++)
		{
			retval = _logical_ops(cmdv[i], &currcmd);
			func_ret = retval;
			if (retval != 0)
				perror(currcmd);
		} 
		return (0);
	}
	else
		return (-1);
} 