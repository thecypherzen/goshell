#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *str = "this";
	char *temp = NULL;
	temp = strdup(str);
	printf("tepm: %s\n", temp);
	printf("len: %lu\n", strlen(str));
}
