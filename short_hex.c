#include "main.h"

/**
 * hhex - prints a short decimal in hexadecimal
 * @arguments: input string
 * @buf: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: number of chars printed
  */
int hhex(va_list arguments, char *buf, unsigned int buffer_index)
{
	short int int_input, i, isnegative, count, first_digit;
	char *hexadecimal, *binary;

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
	hexadecimal = malloc(sizeof(char) * (4 + 1));
	hexadecimal = fill_hex_arr(binary, hexadecimal, 0, 4);
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			buffer_index = handle_buffer(buf, hexadecimal[i], buffer_index);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count);
}
