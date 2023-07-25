#include "main.h"
#include <stdio.h>
/**
 * address - prints the address of an input variable
 * @arguments: input address.
 * @buf: buffer pointer.
 * @buffer_index: index for buffer pointer
 *
 * Return: number of chars printed.
 */

int address(va_list arguments, char *buf, unsigned int buffer_index)
{
	void *add;
	long int int_input;
	int i, count, first_digit, isnegative;
	char *hexadecimal, *binary;
	char nill[] = "(nil)";

	add = (va_arg(arguments, void *));
	if (add == NULL)
	{
		for (i = 0; nill[i]; i++)
			buffer_index = handle_buffer(buf, nill[i], buffer_index);
		return (5);
	}
	int_input = (intptr_t)add;
	isnegative = 0;
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_bin_arr(binary, int_input, isnegative, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = fill_hex_arr(binary, hexadecimal, 0, 16);
	buffer_index = handle_buffer(buf, '0', buffer_index);
	buffer_index = handle_buffer(buf, 'x', buffer_index);
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
	return (count + 2);
}
