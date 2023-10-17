#include "gosh.h"
/**
 * 
 */
int cat_cat(char **agv)
{
	char *buffer;
	size_t sz = 128;
	ssize_t bytes_read, ret_val = 0;
	int fd;
	
	buffer = malloc(sz);
	if (!buffer)
		return (-1);
	
	fd = open(agv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(agv[1]);
		return (-1);
	}
	
	bytes_read = read(fd, buffer, sz);
	while (bytes_read > 0)
	{
		ret_val = write(1, buffer, bytes_read);
		if (ret_val < 0)
			break;
		bytes_read = read(fd, buffer, sz);
        }
	free(buffer), close(fd);
	if (bytes_read < 0 || ret_val < 0)
	{
		perror(agv[1]);
		return (-1);
	}
	return (0);
}