#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_char - prints a char
 * @args: list of arguments
 * @sep: separator string
 */
void print_char(va_list args, char *sep)
{
	printf("%s%c", sep, va_arg(args, int));
}

/**
 * print_int - prints an integer
 * @args: list of arguments
 * @sep: separator string
 */
void print_int(va_list args, char *sep)
{
	printf("%s%d", sep, va_arg(args, int));
}

/**
 * print_float - prints a float
 * @args: list of arguments
 * @sep: separator string
 */
void print_float(va_list args, char *sep)
{
	printf("%s%f", sep, va_arg(args, double));
}

/**
 * print_string - prints a string
 * @args: list of arguments
 * @sep: separator string
 */
void print_string(va_list args, char *sep)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(nil)";
	printf("%s%s", sep, str);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	int i = 0, j;
	char *sep = "";
	va_list args;

	void (*f[])(va_list, char *) = {
		print_char,
		print_int,
		print_float,
		print_string
	};

	char types[] = {'c', 'i', 'f', 's'};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == types[j])
			{
				f[j](args, sep);
				sep = ", ";
			}
			j++;
		}
		i++;
	}

	va_end(args);

	printf("\n");
}
