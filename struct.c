int _printf(const char *format, ...)
{
	dj_structure style[] = {
		{"%s", print_string}, {"%c", print_char},
		{"%%", print_percent},
		{"%i", print_int_number}, {"%d", print_dec_number},
		{"%r", print_reverse_string},
		{"%R", _printf_Rot13}, {"%b", print_binary_number},
		{"%u", print_unint_number},
		{"%o", print_octal_number}, {"%x", print_hex_number},
		{"%X", print_Xhex_number},
		{"%S", print_ascii_number}, {"%p", print_addr_number}
	};