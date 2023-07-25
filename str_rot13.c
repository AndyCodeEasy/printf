#include "main.h"

/**
 * str_rot13 - writes the str in ROT13
 * @arguments: input string
 * @buf: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: number of chars printed.
 */

int str_rot13(va_list arguments, char *buf, unsigned int buffer_index)
{
	char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char nill[] = "(avyy)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			buffer_index = handle_buffer(buf, nill[i], buffer_index);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alf[j]; j++)
		{
			if (str[i] == alf[j])
			{
				k = 1;
				buffer_index = handle_buffer(buf, rot[j], buffer_index);
				break;
			}
		}
		if (k == 0)
			buffer_index = handle_buffer(buf, str[i], buffer_index);
	}
	return (i);
}
