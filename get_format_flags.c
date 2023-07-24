#include "main.h"

/**
 * get_format_flags - Calculates active format_flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Format_flags:
 */

int get_format_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int format_flags = 0;
	const char FORMAT_FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FORMAT_FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FORMAT_FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FORMAT_FLAGS_CH[j])
			{
				format_flags |= FORMAT_FLAGS_ARR[j];
				break;
			}

		if (FORMAT_FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (format_flags);
}
