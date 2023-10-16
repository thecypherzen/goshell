#include "gosh.h"

int main(void)
{
	char cmd[] = "ls non_existent_directory || cd ../; touch NEWFILE.txt && echo $? && echo $$; ls. || lr || ls .;";
	int res;
	
	res = logical_exec(cmd);
	printf("[MAIN]res: %d\n", res);
	return (0);
}

/* printf("command: %s\n", command);
   printf("comd: %s\n", comd);
   while (command[ret])
   {
	   printf("%c\n", command[ret]);
	   if (command[ret] == ' ')
		   n++;
	   ret++;
   }
   printf("tokens: %d\n", n);
   ret = 0; 
   token = strtok(command, " ");
   while (token)
   {
	   printf("Token %d: %s\n", ++ret, token);
	   token = strtok(NULL, " ");
   } */