#include "gosh.h"
#include <stdio.h>

/**
 * main - Entry point
 * Description goes here
 * Return: 0 always
 */
int main(void)
{
	char **vector, str[] = "for the;love of the;father;";
	int i = 0;

	vector = make_vectr(str, ";");
	while (vector[i])
	{
		printf("%s\n", vector[i]);
		i++;
	}
	free_vectr(vector), free(vector);
	return (0);
}
