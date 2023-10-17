#include "gosh.h"

/* handle_ptr_err - Handles errors with pointers
@msg: the error prefix to print. A null terminated string
return: always NULL
*/

int handle_err(char *msg, int val)
{
	perror(msg);
	return (val);
}