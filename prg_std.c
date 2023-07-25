#include "main.h"
#include <stdio.h>

/**
 * prg_std - writes the character c to stdout
 * @a: input char
 * @buf: buffer pointer
 * @i: index for buffer pointer
 * Return: On success 1.
 */
int prg_std(va_list a __attribute__((unused)), char *buf, unsigned int i)
{
	handle_buffer(buf, '%', i);

	return (1);
}
