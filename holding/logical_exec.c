#include "gosh.h"
/**
 * logical_exec - executes logical and/or operations delimited with
 * ; sequentially.
 * @gcmdln: the user-entered command from stdin
 * Return: 0 on success, -1 on failure
 */
int logical_exec(char *gcmdln)
{
	size_t  i = 0;
	char *cmdstr, **cmdv, *currcmd;
	int retval, syntax_err;
	extern int func_ret;

	syntax_err = _syntax_checkr(&cmdstr, gcmdln);
	if (!syntax_err)
	{
		cmdv = make_vectr(cmdstr, ";");
		if (!cmdv)
			return (-1);
		for (i = 0; cmdv[i]; i++)
		{
			retval = _logical_ops(cmdv[i], &currcmd);
			func_ret = retval;
			if (retval != 0)
				perror(currcmd);
		}
		free_vectr(cmdv), free(cmdv);
		return (0);
	}
	else
		return (-1);
}
