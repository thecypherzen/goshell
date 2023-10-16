#include "gosh.h"

int _cpyto_cmdstr(char *token, char **cmdstr)
{
	int i, k, len, j, matched;
	char c1, c2, s_lops[] = {';', '&', '|', '\0'};

	i = k = 0;
	while (token[i] && token[i + 1])
	{
		c1 = token[i], c2 = token[i + 1];
		matched = _slops_comp(s_lops, c1, c2);
		if (matched < 0)
			return (throw_syntax_err(1, c2));
		else
		{ 
			len = strlen(*cmdstr);
			j = len ? len : 0;
			if (j > 0 && !k)
				(*cmdstr)[j] = ' ', j++;
			(*cmdstr)[j] = c1, j++, k++;
			(*cmdstr)[j] = c2, j++;
			if (matched == 1)
				(*cmdstr)[j] = ' ', j++;
			(*cmdstr)[j] = '\0';
			i += 2;
		}
	}
	if (token[i])
	{
		j = strlen(*cmdstr);
		(*cmdstr)[j] = token[i];
		(*cmdstr)[j + 1] = '\0';
	}
	return (0);
}