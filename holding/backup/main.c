#include "gosh.h"

int main(void)
{
	char str[] = "(laugh)";
	char *ptr;

	ptr = _dequoter(str);
	printf("ptr: %s\n", ptr);
}