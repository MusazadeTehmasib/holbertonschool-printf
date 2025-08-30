#include "main.h"

/**
 * print_string - prints a string
 * @str: string to print
 * Return: number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}


/**
 * _putchar - writes a character to stdout
 * @c: the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * handle_format - handles format specifiers
 * @fmt: format specifier character
 * @args: argument list
 * Return: number of characters printed
 */

int handle_format(char fmt, va_list args)
{
	int count = 0;

	if (fmt == 'c')
		count += _putchar(va_arg(args, int));
	else if (fmt == 's')
		count += print_string(va_arg(args, char *));
	else if (fmt == '%')
		count += _putchar('%');
	else if (fmt == 'd' || fmt == 'i')
		count += print_number(va_arg(args, int));
	else
	{
		count += _putchar('%');
		count += _putchar(fmt);
	}
	return (count);
}

/**
 * _printf - simplified printf function
 * @format: format string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				va_end(args);
				return (-1);
			}
			count += handle_format(format[i], args);
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (count);
}
