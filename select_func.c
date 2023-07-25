#include "main.h"
/**
 * select_func - selects the correct function to perform the operation.
 * @s: argument indentifier
 * @index: index for argument indentifier
 * Return: pointer to a function.
 */

int (*select_func(const char *s, int index))(va_list, char *, unsigned int)
{
	print_t pr[] = {
		{"c", character}, {"s", str},
		{"i", integer}, {"d", integer},
		{"b", binary}, {"u", unsigned_int},
		{"o", octal}, {"x", hexadecimal},
		{"X", uppex_hex}, {"S", usr},
		{"p", address}, {"li", lint},
		{"ld", lint}, {"lu", lunt},
		{"lo", loct}, {"lx", lhex},
		{"lX", lupx}, {"hi", hint},
		{"hd", hint}, {"hu", hunt},
		{"ho", hoct}, {"hx", hhex},
		{"hX", hupx}, {"#o", noct},
		{"#x", nhex}, {"#X", nupx},
		{"#i", integer}, {"#d", integer},
		{"#u", unsigned_int}, {"+i", pint},
		{"+d", pint}, {"+u", unsigned_int},
		{"+o", octal}, {"+x", hexadecimal},
		{"+X", uppex_hex}, {" i", sint},
		{" d", sint}, {" u", unsigned_int},
		{" o", octal}, {" x", hexadecimal},
		{" X", uppex_hex}, {"R", str_rot13},
		{"r", reverse}, {"%", prg_std},
		{"l", prg_std}, {"h", prg_std},
		{" +i", pint}, {" +d", pint},
		{"+ i", pint}, {"+ d", pint},
		{" %", prg_std}, {NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (pr[i].type_arg)
	{
		if (s[index] == pr[i].type_arg[j])
		{
			if (pr[i].type_arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (pr[i].f);
}
