#include "gosh.h"
/*
 * _getparent_path - gets the abs path of the parent of cwd
 * @cwd: absolute path to cwd
 * Return: pointer to parent string,
 */
char *_getparent_path(char *cwd)
{
	size_t i, j;
	char *parent = NULL;
	if (cwd)
	{
		i = strlen(cwd) - 1;
	
		/* find the last occurence of */
		while (cwd[i] != '/')
			i--;
		parent = malloc(i);
		if (!parent)
			return (NULL);
		for (j = 0; j < i; j++)
			parent[j] = cwd[j];
		parent[j] = '\0';
		printf("[in_getparent_path func:] freing cwd...");
		printf("=> SUCCESSFUL\n");
	}
	return (parent);
}