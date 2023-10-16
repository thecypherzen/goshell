#include "main.h"

/**
 * print_int_number - a function that prints integers
 * @num: number passed as argument
 * Return:  count of printed integers
 */

int gosh_print_int_number(int num)
{
	int num_len = 0;

	if (num < 0)
	{
		num_len += djput('-');
		num = num * -1;
	}
	if (num >= 0 && num <= 9)
	{
		num_len += djput(num + '0');
	}
	if (num > 9)
	{
		print_int_number(num / 10);

		num_len += djput(num % 10 + '0');
	}
	return (num_len);
}