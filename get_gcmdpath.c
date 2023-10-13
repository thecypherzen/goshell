#include "gosh.h"

char  *get_gcmdpath(char **agv)
{
	char c = agv[0][0];
	char *abs_path = NULL, *temp;
	
	printf("in get_gcmdpath func\n");
	printf("in get_gcmdpath: c = %c, agv[0] = %s\n", c, agv[0]);
	if (c < 65 || (c > 90 && c < 97) || c > 122)
	{
		/* expansion should happen in here */
		printf("passing [%s] to expander\n", agv[0]);
		temp = _gcmdpath_expandr(agv[0]);
		if (!temp)
		{
			printf("IN GET_GCMDPATH: prefix construction fail.\n");
			return (NULL);
		}
		else
		{
			abs_path = temp;
			printf("abs path: %s\n", abs_path);
		}
	}
	else
	{
		temp = _getfull_path(agv[0], getenv("PATH"), 0);
		if (!temp)
		{
			printf("using $PATH has a slight err\n");
			return (NULL);
		}
		abs_path = temp;
	}
	return (abs_path);
}