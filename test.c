#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	char name[] = "The Fine #Man Kelv!";
	printf("name before: %s\n", name);
	char *ptr = strchr(name, '#');
	if (ptr)
		*ptr = '\0';
	printf("name after: %s\n", name);
	return(0);
}