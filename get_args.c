#include "gosh.h"
/*
 * get_args - tokenises the cmdln and passes to the cmd 
 * executor function
 * - create a vector and save the tokens in it
 * - the delimiter used for tokenisation is " "
 * @gcmdln: the command line entered by the user
 * Return: the vector of the tokens on success. NULL otherwise
*/
char **get_args(char *gcmdln)
{
	char *token, **agv;
	size_t agv_sz = 8, i = 0;
	if (!gcmdln)
		return (NULL);
	agv = malloc(sizeof(char *) * agv_sz); /* remembr 2 free */
	if (!agv)
		return (NULL); /* memory failure */
	token = strtok(gcmdln, " ");
	while (token)
	{
		agv[i] = token, i++;
		if (i == agv_sz)
		{
			agv = realloc(agv, agv_sz += 8);
			if (!agv)
				return (NULL);
		}
		
		token = strtok(NULL, " ");
	}
	agv[i] = NULL; /* also pass to g_history */
	return (agv);
}
int func_ret = 0;
int main(void)
{
	while (1)
	{
		char **agv = NULL, *gcmdln = NULL, *gprompt = "($) ";
		ssize_t ret, write_res;
		size_t gsize = 0;
		int func_ret;

		write_res = write(1, gprompt, strlen(gprompt));
		if (write_res < 0)
			return (handle_err("Write Failed", 1));
		
		ret = getline(&gcmdln, &gsize, stdin);
		/* get arguments if res is valid */
		if (ret > 0 && gcmdln[0] != '\n')
		{
			gcmdln[ret - 1] = '\0';
			func_ret = islogical_checkr(gcmdln);
			printf("is logical:%d\n", func_ret);
			if (func_ret < 0) /* gcmdln is null */
				perror(gcmdln);
			else if (func_ret == 0) /* for gcmd_exec */
			{
				agv = get_args(gcmdln);
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