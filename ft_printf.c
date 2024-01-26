/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:43:10 by aschenk           #+#    #+#             */
/*   Updated: 2024/01/26 22:42:27 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

// Util Functions as found in ft_printf_utils.c
int	print_count_char(char _char);
int	print_count_string(char *str);
int	print_count_unsigned(unsigned int nbr);
int	print_count_number(int nbr);
int	print_count_hex(uintptr_t nbr, char format);

//	%p: Prints the memory address represented by a pointer,
//	including the '0x' prefix to indicat e hexadecimal (base 16) notation.
//	Returns the printout length or '(nil)' if the pointer is NULL.
static int	print_count_pointer(uintptr_t ptr)
{
	if (!ptr)
		return (print_count_string("(nil)"));
	else
		return (print_count_string("0x") + print_count_hex(ptr, 'x'));
}

/*
Processes and prints formatted data based on the given format specifier.

@format:	A char representing the format specifier to determine the
			type of data to print.
@args:		A va_list containing the variable arguments
			-> arguments after format string in ft_printf function call.

Returns:	The total printout length of the formatted data
			or -1 in case of an unsupported format specifier.
*/
static int	print_count_format(const char format, va_list args)
{
	int		len_format;

	len_format = 0;
	if (format == 'c')
		len_format = print_count_char(va_arg(args, int));
	else if (format == 's')
		len_format = print_count_string(va_arg(args, char *));
	else if (format == 'p')
		len_format = print_count_pointer((uintptr_t)va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len_format = print_count_number(va_arg(args, int));
	else if (format == 'u')
		len_format = print_count_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len_format = print_count_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len_format = print_count_char('%');
	else
		return (-1);
	return (len_format);
}

/*
A simplified implementation of the printf function in C.

@format:	A format string containing placeholders for various data types.
			Supported format specifiers: 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'.
@...:		Variable arguments to be formatted according to the format string.

Returns:	The total length of characters printed.

Iterates through the format string, replacing placeholders with
actual values from the variable arguments.
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	i = 0;
	total_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]) != 0)
		{
			total_len += print_count_format(format[i + 1], args);
			i++;
		}
		else
			total_len += print_count_char(format[i]);
		i++;
	}
	va_end(args);
	return (total_len);
}
