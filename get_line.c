#include "gosh.h"
static char *ibuff;
static ssize_t tot_bytes_read, bytes_read = 0, offset = 0;


ssize_t get_line(char **line, size_t *sz, FILE *stream)
{
	static char *ibuff = NULL;
	static ssize_t res = 0, offset = 0, tot_bytes_read, buff_len = 128;
	ssize_t bytes_read = 0, line_len;
	int fp = stream->_fileno, i;
	char c;

	if (!(*line) || !sz)
	{
		*sz = 120, *line = malloc(*sz);
		if (!(*line))
			return (-1);
	}
	if (!ibuff)
	{
		ibuff = malloc(buff_len);
		{
			if (!ibuff)
				return (-1);
		}
	}
	do
	{
		if (offset == buff_len)
		{
			ibuff = realloc(ibuff, buff_len += 128);
			if (!ibuff)
				return (bytes_read);
		}
		res = read(fp, ibuff + (size_t)tot_bytes_read, buff_len);
		if (res < 0 || (!res && !tot_bytes_read))
			return (-1);
		if (res)
		{
			tot_bytes_read += res;
			do
			{
				i = 0, c = ibuff[offset];
				(*line)[i] = ibuff[offset], i++, offset++, 
					bytes_read++;
				if (i == ((*sz) - 1))
				{
					(*sz) += 120;
					*line = realloc(*line, (*sz));
					if (!(*line))
						return (bytes_read);
				}	
				
			} while (c != '\n' && offset < tot_bytes_read);
			if (c == '\n' || ((offset == tot_bytes_read) 
				&& tot_bytes_read < buff_len))
			{
				(*line)[i] = '\0';
				free(ibuff);
				return (bytes_read);
			}
		}
	} while (res > 0);
	free(ibuff);
	return (bytes_read);
}

