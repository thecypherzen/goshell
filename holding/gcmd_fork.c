#include "gosh.h"

int gcmd_fork(char *full_path, char **agv)
{
	pid_t gpid;
	int ret_stat;
	
	if (!full_path)
		return (-1);
	gpid = fork();
	if (gpid < 0)
		return (-1);
	if (!gpid)
	{
		if (execve(full_path, agv, NULL) < 0)
			return (-1);
	}
	else
	{
		wait (&ret_stat);
	}
	return (ret_stat);
}