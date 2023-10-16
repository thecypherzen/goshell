#include "gosh.h"

int touch_touch(char **agv)
/* Handle the touch command */
{
	int fd = open(agv[1], O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		perror(agv[1]);
		return -1;
	}
	close(fd);
	return (0);
}