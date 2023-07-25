#include "main.h"

/**
 * binary - prints decimal in binary
 * @arguments: input string
 * @buf: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: number of chars printed.
 */

int binary(va_list arguments, char *buf, unsigned int buffer_index)
{
	int int_input, count, i, first_one, isnegative;
	char *binary;

	int_input = va_arg(arguments, int);
	isnegative = 0;
	if (int_input == 0)
	{
		buffer_index = handle_buffer(buf, '0', buffer_index);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_bin_arr(binary, int_input, isnegative, 32);
	first_one = 0;
	for (count = i = 0; binary[i]; i++)
	{
		if (first_one == 0 && binary[i] == '1')
			first_one = 1;
		if (first_one == 1)
		{
			buffer_index = handle_buffer(buf, binary[i], buffer_index);
			count++;
		}
	}
	free(binary);
	return (count);
}
