#include "main.h"

/**
 * str - writes the string to stdout
 * @arguments: input string
 * @buf: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: On success 1.
 */
int str(va_list arguments, char *buf, unsigned int buffer_index)
{
	char *str;
	unsigned int i;
	char nill[] = "(null)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			buffer_index = handle_buffer(buf, nill[i], buffer_index);
		return (6);
	}
	for (i = 0; str[i]; i++)
		buffer_index = handle_buffer(buf, str[i], buffer_index);
	return (i);
}
