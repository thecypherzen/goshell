#include "gosh.h"

/*
 * _exit_exec - makes exit syscall for gcmd_exec & frees vector
 * @agv: argument vector to get command from;
 * return: void;
*/

void _exit_exec(char **agv)
{
	int exit_status = agv[1] ? atoi(agv[1]) : 0;
	free(agv);
	exit(exit_status);
}
/* "exit" "98" "NULL"*/
