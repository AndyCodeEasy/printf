#include "main.h"

/**
 * sint - prints int begining with space
 * @arguments: input string
 * @buf: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: number of chars printed
 */
int sint(va_list arguments, char *buf, unsigned int buffer_index)
{
	int int_input;
	unsigned int int_in, int_temp, i, div;

	int_input = va_arg(arguments, int);
	if (int_input < 0)
	{
		int_in = int_input * -1;
		buffer_index = handle_buffer(buf, '-', buffer_index);
	}
	else
	{
		int_in = int_input;
		buffer_index = handle_buffer(buf, ' ', buffer_index);
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
	return (i + 1);
}
