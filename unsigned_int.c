#include "main.h"
/**
 * unsigned_int - prints an unsigned int
 * @arguments: number to print
 * @buf: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: number of chars printed.
 */
int unsigned_int(va_list arguments, char *buf, unsigned int buffer_index)
{
	unsigned int int_in, int_temp, i, div;

	int_in = va_arg(arguments, unsigned int);
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
	return (i);
}
