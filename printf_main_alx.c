/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main_alx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:43:10 by aschenk           #+#    #+#             */
/*   Updated: 2024/01/23 17:37:51 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_puthexa(unsigned int n, char format); //

// %c Prints a single character.
int	print_count_char(char _char)
{
	ft_putchar_fd(_char, 1);
	return (1);
}

// %s Prints a string.
int	print_count_string(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// Adjustment of ft_putnbr_fd() from libft.a to include return of length.
int	print_count_number(int nbr)
{
	int	nbr_length;

	nbr_length = 0;
	if (nbr == -2147483648)
	{
		nbr_length += print_count_char('-') + print_count_char('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		nbr_length = print_count_char('-');
		nbr *= -1;
	}
	if (nbr < 10)
		nbr_length = print_count_char(nbr + '0');
	else
	{
		nbr_length += print_count_number(nbr / 10);
		nbr_length += print_count_number(nbr % 10);
	}
	return (nbr_length);
}

// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
int	print_count_hex(unsigned int nbr, char format)
{
	char	*lower;
	char	*upper;
	char	*hex_chars;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	if (format == 'x')
		hex_chars = lower;
	else
		hex_chars = upper;
	if (nbr < 16)
		return (print_count_char(hex_chars[nbr]));
	else
		return (print_count_hex(nbr / 16, format)
			+ print_count_char(hex_chars[nbr % 16]));
}

int	print_count_pointer(void *format)
{
	unsigned long	n;

	n = (unsigned long)format;
	if (n == 0)
		return (print_count_string("(nil)"));
	else
	{
		return (print_count_string("0x") + print_count_hex(n, 'x'));
	}
}

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count += print_count_char(0 + '0');
	else if (n < 10)
		count += print_count_char(n + '0');
	else
	{
		count += ft_putunsigned(n / 10);
		count += ft_putunsigned(n % 10);
	}
	return (count);
}

int	ft_format(va_list args, const char *format)
{
	int	x;

	x = 0;
	if (format[x] == 'c')
		return (print_count_char(va_arg(args, int)));
	else if (format[x] == 's')
		return (print_count_string(va_arg(args, char *)));
	else if (format[x] == 'p')
		return (print_count_pointer(va_arg(args, void *)));
	else if (format[x] == 'd' || format[x] == 'i')
		return (print_count_number(va_arg(args, int)));
	else if (format[x] == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format[x] == 'x' || format[x] == 'X')
		return (print_count_hex(va_arg(args, unsigned int), *format));
	else if (format[x] == '%')
		return (print_count_char('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		x;
	int		count;

	x = 0;
	count = 0;
	va_start(args, format);
	while (format[x])
	{
		if (format[x] == '%' && ft_strchr("cspdiuxX%", format[x + 1]))
		{
			count += ft_format(args, &format[x + 1]);
			x++;
		}
		else
			count += print_count_char(format[x]);
		x++;
	}
	va_end(args);
	return (count);
}


#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int		lenght_my_fct;
	int		length_native;
	char	*ptr;

	ptr =  "I am getting pointed at!";
	// Testing w/o any format specificer
	printf("\n== TESTING - No Format Specificer ==\n");
	printf("-- ft_printf(): --\n");
	lenght_my_fct = ft_printf("Just a string!\n"); ////////
	printf("Return value: %d\n", lenght_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Just a string!\n"); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %c
	printf("== TESTING - %%c ==\n");
	printf("-- ft_printf(): --\n");
	lenght_my_fct = ft_printf("Printing a char: %c\n", 'z'); ////////
	printf("Return value: %d\n", lenght_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing a char: %c\n", 'z'); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %s
	printf("== TESTING - %%s ==\n");
	printf("-- ft_printf(): --\n");
	lenght_my_fct = ft_printf("Printing a string: %s\n",
		"Hello World!"); ////////
	printf("Return value: %d\n", lenght_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing a string: %s\n", "Hello World!"); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %d
	printf("== TESTING - %%d ==\n");
	printf("-- ft_printf(): --\n");
	lenght_my_fct = ft_printf("Printing a decimal number: %d\n", 42); ////////
	printf("Return value: %d\n", lenght_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing a decimal number: %d\n", 42); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %i
	printf("== TESTING - %%i ==\n");
	printf("-- ft_printf(): --\n");
	lenght_my_fct = ft_printf("Printing an integer base 10 "
		"(same as decimal): %i\n", 42); ////////
	printf("Return value: %d\n", lenght_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing an integer base 10 "
		"(same as decimal): %i\n", 42); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %p
	printf("== TESTING - %%p ==\n");
	printf("-- ft_printf(): --\n");
	lenght_my_fct = ft_printf("Printing pointer: %p\n", ptr);
	printf("Return value: %d\n", lenght_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing pointer: %p\n", ptr);
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	return (0);
}


/*
#include <stdio.h>
int main(void)
{
    char name[7] = "Daniel";
    int age = -31;
    int result;
    int result2;
    char letter = 'A';
    int hexa = 2566;
    unsigned int big = 3147483648;
    void *address = "random_address";
    void *address2 = "blablabla";
    result = ft_printf("50%%: Name: %s Age: %i Favorite letter: %c Unsigned: %u Hexa low: %x Hexa up: %X Address: %p Address2: %p\n", name, age, letter, big, hexa, hexa, address, address2);
    ft_printf("Characters written: %i\n", result);
    result2 = printf("50%%: Name: %s Age: %i Favorite letter: %c Unsigned: %u Hexa low: %x Hexa up: %X Address: %p Address2: %p\n", name, age, letter, big, hexa, hexa, address, address2);
    printf("Characters written: %i\n", result2);
    return (0);
}*/
