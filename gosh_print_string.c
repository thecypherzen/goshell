#include "main.h"

/**
 * print_string - a function that prints strings
 * @djlist2: argument  passed from va_arg(list, char*)
 * Return: count of printed characters
 */

int gosh_print_string(va_list djlist2)
{
	char *s;
	int i, len;

	s = va_arg(djlist2, char *);
	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (i = 0; i < len; i++)
			djput(s[i]);
		return (len);
	}
	else
	{
		len = _strlen(s);
		for (i = 0; i < len; i++)
			djput(s[i]);
		return (len);
	}
}