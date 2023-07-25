#include "main.h"

/**
 * usr - prints a string and values of
 * non-printed chars
 * @arguments: input string
 * @buf: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: number of chars printed
 */
int usr(va_list arguments, char *buf, unsigned int buffer_index)
{
	unsigned char *str;
	char *hexadecimal, *binary;
	unsigned int i, sum, op;

	str = va_arg(arguments, unsigned char *);
	binary = malloc(sizeof(char) * (32 + 1));
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			buffer_index = handle_buffer(buf, '\\', buffer_index);
			buffer_index = handle_buffer(buf, 'x', buffer_index);
			op = str[i];
			binary = fill_bin_arr(binary, op, 0, 32);
			hexadecimal = fill_hex_arr(binary, hexadecimal, 1, 8);
			buffer_index = handle_buffer(buf, hexadecimal[6], buffer_index);
			buffer_index = handle_buffer(buf, hexadecimal[7], buffer_index);
			sum += 3;
		}
		else
			buffer_index = handle_buffer(buf, str[i], buffer_index);
	}
	free(binary);
	free(hexadecimal);
	return (i + sum);
}

