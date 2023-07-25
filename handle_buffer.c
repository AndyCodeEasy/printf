#include "main.h"

/**
 * handle_buffer - concatenates the buffer characters
 * @buf: buffer pointer
 * @c: charcter to concatenate
 * @buffer_index: index of buffer pointer
 * Return: index of buffer pointer.
 */

unsigned int handle_buffer(char *buf, char c, unsigned int buffer_index)
{
	if (buffer_index == 1024)
	{
		print_buffer(buf, buffer_index);
		buffer_index = 0;
	}
		buf[buffer_index] = c;
		buffer_index++;
		return (buffer_index);
}
