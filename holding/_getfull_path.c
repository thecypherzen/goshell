#include "gosh.h"
/**
 * _getfull_path - gets the abs path of the parent of the cwd
 * @rel-path: the relative path
 * @cwd: absolute path to cwd.
 * @slashed: 1 if to tokenise by slashes(/) or 0 if by (:)
 * Return: pointer to parent string on success.
 *         NULL if access fails or abs_path is NULL. cd goshell
 */ /* PWD=/this/that */
char *_getfull_path(char *rel_path, char *cwd, int slashed)
{
	char *temp = NULL, *full_path = NULL, *cwd_cpy;
	size_t i = 0, j = 0, len_rel = rel_path ? strlen(rel_path) : 0, 
	len_cw = cwd ? strlen(cwd) : 0, found = 0;

	printf("...inside getfullpath func...\n");
	if (slashed) /* ../enters here if rel paths are provided */
	{ /* cd ../ */
		if (*rel_path == '/')
			full_path = rel_path;
		else
		{
			printf("inside slashed func: about to malloc\n");
			while (rel_path[i] != '/' && rel_path[i])
			{
				i++;
				if (rel_path[i] == '/')
					found = 1;
			}
			if (i == len_rel)
				i = 0;
			printf("rel_path len: %lu | cwd_len: %lu\n",
				rel_path ? strlen(rel_path) : 99,
				cwd ? strlen(cwd): 101);
			full_path = malloc((len_rel - (i + 1)) + len_cw + 2); 
			if (!full_path)
			{
				printf("malloc failed\n");
				return (NULL);
			}
			while (cwd[j])
				full_path[j] = cwd[j], j++;
			full_path[j++] = '/';
			if (found)
				i++;
			while(rel_path[i])
				full_path[j] = rel_path[i], i++, j++;
			full_path[j] = '\0';
			
		}
		printf("IN getfull_path func:\n");
		printf("full_path => %s\n", full_path ? full_path : "null");
		return (access(full_path, F_OK | X_OK) == 0 ? 
			full_path : NULL);
	}
	else /* tokenise PATH and find command */
	{
		cwd_cpy = strdup(cwd); temp = strtok(cwd_cpy, ":");
		while (temp) /* /usr/local/sbin */
		{
			full_path = malloc((strlen(temp)) + 
				strlen(rel_path) + 2);
			if (!full_path)
				return (NULL);
			while(temp[i])
				full_path[i] = temp[i], i++;
			full_path[i++] = '/';
			while(rel_path[j])
				full_path[i] = rel_path[j], i++, j++;
			full_path[i] = '\0';
			if (access(full_path, F_OK | X_OK) == 0)
				return (full_path);
			else
			{
				temp = strtok(NULL, ":"), i = j = 0;
				free(full_path);
				full_path = NULL;
			}
		}
		return (full_path);
	}
}
