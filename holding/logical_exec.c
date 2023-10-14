#include "gosh.h"

int main(void)
{
	char comd[] = "ls -l ../ cd ..; los || ls . && ls ..&& pwd; ls -a;";
	int retval = logical_exec(comd);
	printf("retval: %d\n", retval);
	return (0); 
}
int logical_exec(char *comd)
{
	size_t cols = 0, i = 0;
	char **cmdv, *cmdline, *currcmd;
	int retval;
	
	while (comd[i])
	{
		if (comd[i] == ';')
			cols++;
		i++;
	}
	cols++;
	cmdv = malloc(sizeof(char *) * (cols + 1));
	cmdv[cols] = NULL;
	cmdline = strtok(comd, ";"), i = 0;
	while (cols > 0) 
	{
		cmdv[i] = cmdline;
		cmdline = strtok(NULL, ";"), cols--, i++;
	}
	for (i = 0; cmdv[i]; i++)
	{
		retval = _logical_ops(cmdv[i], &currcmd);
		if (retval != 0)
			perror(currcmd);
	}
	return (0);
} 