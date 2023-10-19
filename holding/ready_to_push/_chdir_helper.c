#include "gosh.h"
/**
 * _chdir_helper - Change directory function helper
 * @full_path: Full path to directory
 * @cwd: Current working directory
 * Return: 0 on success, -1 on error
 */
int _chdir_helper(char *full_path, char *cwd)
{
	int retval;

	gosh_printf("....IN _chdir_helper....\n");
	gosh_printf("full_path: %s\ncwd: %s\n", full_path,
		cwd ? cwd : "(IS NULL)");
	if (!full_path || !cwd)
		return (-1);
	if (setenv("OLDPWD", cwd, 1) == 0)
		gosh_printf("\nsetting OLDPWD successful\n");
	else
		gosh_printf("\nSetting OLDPWD failed\n");
	retval = chdir(full_path);
	if (retval == 0)
		gosh_printf("CHDIR successful\n");
	else
	{
		gosh_printf("CHDIR failed. Errno: %i\n",
			errno == ENOENT ? 99 : -111);
	}
	if (setenv("PWD", full_path, 1) == 0)
		gosh_printf("SETVAL of PWD to full_path SUCCESSFUL\n");
	else
		gosh_printf("SETVAL of PWD to full_path FAILED\n\n");
	free(full_path), free(cwd);
	return (retval);
}
