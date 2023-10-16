#include "gosh.h"
/**
 * syntax_checkr - checks for 2 edge cases.
 * 1. Empty commands/syntax errors (multiple operators and separators)
 * Trailing white spaces
 * Return: should be added to other functions.
 */

int _syntax_checkr(char **cmdstr, char *gcmdln)
{
	int i, matched, ret;
        char *cmdl = strdup(gcmdln), *token, 
	*lops[] = {";", "&&", "||", NULL};

	*cmdstr = malloc(strlen(gcmdln) + 1);
	if (!(*cmdstr))
		return (-1);
	(*cmdstr)[0] = '\0';
	if (*cmdl == ';' || *cmdl == '&' || *cmdl == '|')
	{
		if (cmdl[1] == ';' || cmdl[1] == '&' || cmdl[1] == '|')
			return (throw_syntax_err(2, *cmdl, cmdl[1]));
		return (throw_syntax_err(1, *cmdl));
	}
	token = strtok(cmdl, " "); 
	while (token)
	{
		i = matched = 0;
		while(lops[i])
		{
			if (strcmp(token, lops[i]) == 0)
			{
				matched = 1;
				break;
			}
			i++;
		}
		if (matched || strlen(token) == 1)
			strcat((*cmdstr), " "), strcat((*cmdstr), token);
		else
		{ 
			ret = _cpyto_cmdstr(token, cmdstr);
			if (ret < 0)
				return (ret);
		}
		token = strtok(NULL, " ");
	}
	return (0);
}
