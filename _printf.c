#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: the character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_number - prints an integer
 * @n: the integer to print
 * Return: number of characters printed
 */
int print_num(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		count += print_num(num / 10);

	count += _putchar((num % 10) + '0');
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
	char *str;

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
			if (format[i] == 'c')
				count += _putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				while (*str)
					count += _putchar(*str++);
			}
			else if (format[i] == '%')
				count += _putchar('%');
			else if (format[i] == 'd' || format[i] == 'i') /* integer */
				count += print_num(va_arg(args, int));
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
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
