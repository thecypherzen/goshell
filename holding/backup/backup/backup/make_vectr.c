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

	printf("\n...make_vectr func...\n");
	if (!str)
		return (NULL);
	while (str[i++])
	{
		if (str[i - 1] == *delim)
			n++;
	}
	printf("[mvectr]:num of delims: %d\n", n);
	printf("[mvectr]:expected tokens: %d\n", n + 1);
	printf("[mvectr]:size of vectr: %d | ", n + 2);
	n += 2, i = 0;
	printf("%d\n", n);
	vectr = malloc(sizeof(char *) * (n));
	if (!vectr)
	{
		printf("[mvectr]mallocing vectr failed\n");
		return (NULL);
	} /* [][][][][] */
	printf("[mvectr]: malloc successful\n");
	vectr[--n] = NULL, token = strtok(str, delim);
	while (i < n)
	{
		vectr[i] = s_dup(token);
		token = strtok(NULL, delim);
		i++;
	}
	printf("[vectr]: done...returning...\n");
	return (vectr);
}