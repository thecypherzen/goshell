#include "gosh.h"
/**
 * main - Entry point
 */
int func_ret = 10;
int main(void)
{
	while (1)
	{
		char **agv = NULL, *gcmdln = NULL, *gprompt = "($) ";
		ssize_t ret, write_res;
		size_t gsize = 0;
		int func_ret;

		write_res = write(1, gprompt, s_len(gprompt));
		if (write_res < 0)
			return (handle_err("Write Failed", 1));
		
		ret = getline(&gcmdln, &gsize, stdin);
		/* get arguments if res is valid */
		if (ret > 0 && gcmdln[0] != '\n')
		{
			gcmdln[ret - 1] = '\0';
			func_ret = islogical_checkr(&gcmdln);
			printf("is logical:%i\n", func_ret);
			if (func_ret < 0) /* gcmdln is null */
				perror(gcmdln);
			else if (func_ret == 0) /* for gcmd_exec */
			{
				agv = make_vectr(gcmdln, " ");
				if (!agv)
					perror(gcmdln);
				else
				{
					func_ret  = gcmd_exec(agv);
					if (func_ret < 0)
						perror(agv[0]);
				}
			}
			else
			{
				func_ret = logical_exec(gcmdln);
			}
			if (gcmdln)
				free(gcmdln);
		}
		else if (ret < 0)
		{
			s_write('\n');
			return (0);
		}
	}
	return (0);
}