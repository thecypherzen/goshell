#include "gosh.h"

int logical_exec(char *gcmdln)
{
	size_t cols = 0, i = 0;
	char *cmdstr, **cmdv, *cmdline, *currcmd;
	int retval, syntax_err;

	syntax_err = _syntax_checkr(&cmdstr, gcmdln);
	if (!syntax_err)
	{
		printf("cmdstr:\n%s\nSyntax_err: %d\n", 
			cmdstr, syntax_err);
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
			cmdv[0] = cmdstr;
		printf("\n*** commands entered ***\n");
		for (i = 0; cmdv[i]; i++)
		{
			/*retval = _logical_ops(cmdv[i], &currcmd);
			retval = 0;
			if (retval != 0)
				perror(currcmd); */
			printf("[%lu] %s\n", i + 1, cmdv[i]);
		} 
		printf("\n");
		free(cmdstr);
		return (0);
	}
	else
	{
		free(cmdstr);
		printf("Some error occured\n");
		return (-1);
	}
	(void)currcmd, (void)retval;
} 