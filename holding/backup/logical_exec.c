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

	printf(".........inside logical_exec func.............\n");
	printf("gcmdln: %s\n", gcmdln);
	syntax_err = _syntax_checkr(&cmdstr, gcmdln);
	printf("sytax err: %d\n", syntax_err);
	if (!syntax_err)
	{
		printf("[logical exec]: no syntax error found\n");
		while (cmdstr[i])
		{
			if (cmdstr[i] == ';')
				cols++;
			i++;
		}
		cols++, i = 0;
		printf("about to malloc\n");
		cmdv = malloc(sizeof(char *) * (cols + 1));
		printf("malloc successful\n");
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
		{
			cmdv[0] = strdup(cmdstr);
			/*free(cmdstr); */
		}
		/*printf("\n*** commands entered ***\n"); */
		for (i = 0; cmdv[i]; i++)
		{
			printf("[curcmd]:\n%s\n", cmdv[i]);
			retval = _logical_ops(cmdv[i], &currcmd);
			func_ret = retval;
			printf("retval: %d\n", retval);
			if (retval != 0)
				perror(currcmd);
		} 
		printf("\n");
		return (0);
	}
	else
	{
		printf("Some error occured\n");
		return (-1);
	}
} 