#include "gosh.h"

char *_gcmdpath_expandr(char *rel_path)
{
	char *abs_path = NULL, *temp = NULL, 
	rel_ids[] = {'.', '/', '~', '\0'}, c = *rel_path;
	int i = 0;
	
	printf("In path expandr: %s | c = %c\n", rel_path, c);
	while (rel_ids[i])
	{
		printf("rel_path: %c | rel_char: %c\n", 
			c, rel_ids[i]);
		if (c == rel_ids[i])
			break;
		i++;
	}
	if (!i)
	{ 
		if (rel_path[1] == '.' && (rel_path[2] == '/'))
		{
			temp = _getparent_path(getenv("PWD"));
			if (!temp)
			{
				printf("Returning NULL(TEMP)\n");
				return (NULL);
			}
			return (abs_path = _getfull_path(rel_path, 
				temp, 1));
		}
		else if (rel_path[1] == '/')
			return (abs_path = _getfull_path(rel_path, 
				getenv("PWD"), 1));
		return (abs_path = NULL);
	}
	else if (i == 1)
		abs_path = _getfull_path(rel_path, "/", 1);
	else if (i == 2)
	{
		if (rel_path[1] == '/')
			return (abs_path = _getfull_path(rel_path,
				getenv("HOME"), 1));
		return (abs_path = NULL);
	}
	return (abs_path);
}