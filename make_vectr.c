#include "gosh.h"

/**
 * make_vectr: makes a vector from a string based usiing a delimiter
 * @str: the string
 * @delim: the delimiting string
 * Return: ptr to the vecor on success.
 *         NULL otherwise or if error
 */
char **make_vectr(char *str, char *delim)
{
	char **vectr, *token;
	int n = 0, i = 0;
	printf("make vectr func\n");
	if (!str)
		return (NULL);
	while (str[i++])
	{
		if (str[i - 1] == *delim)
			n++;
	}
	n += 2, i = 0;
	printf("about to malloc\n");
	vectr = malloc(sizeof(char *) * (n));
	if (!vectr)
		return (NULL);
	printf("malloc successful\n");
	vectr[n] = NULL, token = strtok(str, delim);
	while (n > 1)
	{
		vectr[i] = token;
		token = strtok(NULL, delim);
		i++, n--;
	}
	i = 0;
	return (vectr);
}