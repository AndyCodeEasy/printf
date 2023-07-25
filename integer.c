#include "main.h"

/**
 * integer - prints an integer
 * @arguments: input string
 * @buf: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: number of chars printed.
 */

int integer(va_list arguments, char *buf, unsigned int buffer_index)
{
	int int_input;
	unsigned int int_in, int_temp, i, div, isneg;

	int_input = va_arg(arguments, int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		buffer_index = handle_buffer(buf, '-', buffer_index);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}

	int_temp = int_in;
	div = 1;

	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		buffer_index = handle_buffer(buf, ((int_in / div) % 10) + '0', buffer_index);
	}
	return (i + isneg);
}
