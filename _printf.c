#include "main.h"

/**
 * _printf – formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of printed chars
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, printed_chars = 0, buffer_index = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buffer(buffer, buffer_index), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = select_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handle_buffer(buffer, format[i], buffer_index), printed_chars++, i--;
				}
				else
				{
					printed_chars += function(arguments, buffer, buffer_index);
					i += ret_print_id(format, i + 1);
				}
			} i++;
		}
		else
			handle_buffer(buffer, format[i], buffer_index), printed_chars++;
		for (buffer_index = printed_chars; buffer_index > 1024; buffer_index -= 1024)
			;
	}
	print_buffer(buffer, buffer_index), free(buffer), va_end(arguments);
	return (printed_chars);
}

