#include "gosh.h"

char *_dequoter(char *strval)
{
	char a = '\'', b = '\"', c = '\0', *newstr;
	size_t i = 0, len = strlen(strval), sz = 0;
	ssize_t n;

	printf("strval: %s\n", strval);
	if ((*strval == a && strval[len - 1]  != a) ||
		(*strval == b && strval[len - 1] != b))
	{
		n = write(1, "> ", 2);
		if (n <= 0)
			return (NULL);
		n = read(0, &c, 1);
		if (n <= 0 || c != strval[0])
			return (NULL);
		sz = n + len;
	}
	if ((*strval = a && strval[len - 1] == a) ||
		(*strval = b && strval[len - 1] == b))
	{
		newstr = malloc(sz ? sz : len--);
		if (!newstr)
			return (NULL);
		for (i = 1; i < len; i++)
			newstr[i - 1] = strval[i];
		if (sz)
			newstr[i - 1] = c, i++, 
				newstr[i] = '\0';
		else
			newstr[i - 1] = '\0';
		return (newstr);
	} 
	return (NULL);
}
