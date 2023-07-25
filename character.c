#include "main.h"
#include <stdio.h>
/**
 * character - writes the character c to stdout
 * @arguments: input char
 * @buf: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: On success 1.
 */
int character(va_list arguments, char *buf, unsigned int buffer_index)
{
	char c;

	c = va_arg(arguments, int);
	handle_buffer(buf, c, buffer_index);

	return (1);
}
