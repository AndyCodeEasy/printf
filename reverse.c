#include "main.h"

/**
 * reverse - writes the str in reverse
 * @arguments: input string
 * @buf: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: number of chars printed.
 */
int reverse(va_list arguments, char *buf, unsigned int buffer_index)
{
	char *str;
	unsigned int i;
	int j = 0;
	char nill[] = "(llun)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
		buffer_index = handle_buffer(buf, nill[i], buffer_index);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
	{
		buffer_index = handle_buffer(buf, str[j], buffer_index);
	}
	return (i);
}
