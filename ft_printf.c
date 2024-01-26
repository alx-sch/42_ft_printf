/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:43:10 by aschenk           #+#    #+#             */
/*   Updated: 2024/01/27 00:38:24 by aschenk          ###   ########.fr       */
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
//	including the '0x' prefix to indicate hexadecimal (base 16) notation.
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
			or '0' for invalid format specifier/
*/
static int	print_count_specifier(const char specifier, va_list args)
{
	int		len_specifier;

	len_specifier = 0;
	if (specifier == 'c')
		len_specifier = print_count_char(va_arg(args, int));
	else if (specifier == 's')
		len_specifier = print_count_string(va_arg(args, char *));
	else if (specifier == 'p')
		len_specifier = print_count_pointer((uintptr_t)va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		len_specifier = print_count_number(va_arg(args, int));
	else if (specifier == 'u')
		len_specifier = print_count_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		len_specifier = print_count_hex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		len_specifier = print_count_char('%');
	return (len_specifier);
}

static int	return_error(va_list args)
{
	va_end(args);
	return (-1);
}

/*
A simplified implementation of the printf function in C.

@format:	A format string containing placeholders for various data types.
			Supported format specif ers: 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'.
@...:		Variable arguments to be formatted according to the format string.

Returns:	The total length of characters printed. Returns '-1' when an error
			occurred (here: if '%' is last character of the format string).

Iterates through the format string, replacing placeholders with
actual values from the variable argument list.
*/
int	ft_printf(const char *format, ...)
{
	int		i;
	int		total_len;
	va_list	args;

	i = 0;
	total_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (return_error(args));
			if (ft_strchr("cspdiuxX%", format[i + 1]))
				total_len += print_count_specifier(format[i + 1], args);
			else
				total_len += print_count_char(format[i]);
			i++;
		}
		else
			total_len += print_count_char(format[i]);
		i++;
	}
	va_end(args);
	return (total_len);
}
