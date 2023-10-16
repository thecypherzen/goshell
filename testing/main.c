#include "gosh.h"

int main(void)
{
	char cmd[] = "ls non_existent_directory || cd ../; touch NEWFILE.txt && echo $? && echo $$; ls. || lr || ls .;";
	int res;
	
	res = logical_exec(cmd);
	printf("[MAIN]res: %d\n", res);
	return (0);
}