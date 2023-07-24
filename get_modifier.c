#include "main.h"

/**
 * get_modifier - Calculates the modifier to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: Arguments of arguments to be total_printed.
 *
 * Return: Precision.
 */

int get_modifier(const char *format, int *i)
{
	int curr_i = *i + 1;
	int modifier = 0;

	if (format[curr_i] == 'l')
		modifier = S_LONG;
	else if (format[curr_i] == 'h')
		modifier = S_SHORT;

	if (modifier == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (modifier);
}
