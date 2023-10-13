#include "gosh.h"
/*
 * _get_parent_path - gets the abs path of the parent of cwd
 * @cwd: absolute path to cwd ./ ../ / ~/ 
 * Return: pointer to parent string,
 */  /* ls  /usr/home/utils/bin/bash/bin/bash/ls */
char *_getfull_path(char *rel_path, char *cwd, int slashed)
{
	char *temp = NULL, *full_path = NULL;
	size_t i = 0, j = 0;
	
	if (slashed)
	{
		if (*rel_path == '/')
			return (full_path = rel_path);
		while (rel_path[i] != '/')
			i++;
		full_path = malloc((strlen(rel_path) - i) +
			strlen(cwd) + 1);
		if (!full_path)
			return (NULL);
		while (cwd[j])
			full_path[j] = cwd[j], j++;
		while(rel_path[i])
			full_path[j] = rel_path[i], i++, j++;
		full_path[j] = '\0';
		printf("INGFP FUNC: fullpath: %s\n", full_path);
		return (access(full_path, F_OK | X_OK) == 0 ? 
			full_path : NULL);
	}
	else /* tokenise PATH and find command */
	{
		temp = strtok(cwd, ":");
		printf("PATH: %s\n", cwd);
		while (temp)
		{
			full_path = malloc((strlen(temp)) + 
				strlen(rel_path) + 1);
			if (!full_path)
				return (NULL);
			while(temp[i])
				full_path[i] = temp[i], i++;
			while(rel_path[j])
				full_path[i] = rel_path[j], i++, j++;
			full_path[j] = '\0';
			printf("INGFP FUNC: fullpath: %s\n", full_path);
			if (access(full_path, F_OK | X_OK) == 0)
				return (full_path);
			temp = strtok(NULL, ":");
			i = j = 0;
			free(full_path);
		}
		return (NULL);
	}
}