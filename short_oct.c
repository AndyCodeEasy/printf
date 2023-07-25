#include "main.h"

/**
 * hoct - prints long decimal number in octal
 * @arguments: input number
 * @buf: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: number of chars printed.
 */
int hoct(va_list arguments, char *buf, unsigned int buffer_index)
{
	short int int_input, i, isnegative, count, first_digit;
	char *octal, *binary;

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
	binary = malloc(sizeof(char) * (16 + 1));
	binary = fill_bin_arr(binary, int_input, isnegative, 16);
	octal = malloc(sizeof(char) * (6 + 1));
	octal = fill_shrt_oct_arr(binary, octal);
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			buffer_index = handle_buffer(buf, octal[i], buffer_index);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}
