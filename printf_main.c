/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:43:10 by aschenk           #+#    #+#             */
/*   Updated: 2024/01/22 23:56:04 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);


// int	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// 	return (1);
// }

// int	ft_putstr(char *str)
// {
// 	int	x;

// 	x = 0;
//     if (str == NULL)
//     {
//         x = 6;
//         write(1, "(null)", 6);
//         return (x);
//     }
// 	while (str[x])
// 	{
// 		write(1, &str[x], 1);
// 		x++;
// 	}
// 	return (x);
// }

int	ft_addressprint(unsigned long n)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n < 16)
		return (ft_putchar(hexa[n]));
	else
		return (ft_addressprint(n / 16) + ft_putchar(hexa[n % 16]));
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int		x;
// 	char	cc;

// 	x = 0;
// 	cc = (char) c;
// 	while (s[x])
// 	{
// 		if (s[x] == cc)
// 			return ((char *) &s[x]);
// 		x++;
// 	}
// 	if (s[x] == cc)
// 		return ((char *) &s[x]);
// 	return (NULL);
// }

int	ft_putaddress(void *format)
{
	int				count;
	unsigned long	n;

	count = 0;
	n = (unsigned long)format;
	if (format == NULL)
    {
        count = 5;
        write(1, "(nil)", 5);
		return (count);
    }
	else
	{
		count = ft_putstr("0x");
		count += ft_addressprint(n);
	}
	return (count);
}

// int	ft_nbrlen(int n)
// {
// 	int	x;

// 	x = 1;
// 	if (n < 0)
//     {
//         n = -n;
// 		x = 2;
//     }
// 	while (n >= 10)
// 	{
// 		n /= 10;
// 		x++;
// 	}
// 	return (x);
// }

// int	ft_putnbr(int n)
// {
// 	int	x;

// 	x = ft_nbrlen(n);
// 	if (n == -2147483648)
//     {
// 		write(1, "-2147483648", 11);
//         x = 11;
//         return (x);
//     }
// 	else if (n < 0)
// 	{
// 		ft_putchar('-');
// 		n = -n;
// 		ft_putnbr(n);
// 	}
// 	else if (n < 10)
// 		ft_putchar(n + 48);
// 	else
// 	{
// 		ft_putnbr(n / 10);
// 		ft_putnbr(n % 10);
// 	}
// 	return (x);
// }

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count += ft_putchar(0 + '0');
	else if (n < 10)
		count += ft_putchar(n + '0');
	else
	{
		count += ft_putunsigned(n / 10);
		count += ft_putunsigned(n % 10);
	}
	return (count);
}

int	ft_puthexa(unsigned int n, char format)
{
	char	*lower;
	char	*upper;
	char	*needed;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	if (format == 'x')
		needed = lower;
	else
		needed = upper;
	if (n < 16)
		return (ft_putchar(needed[n]));
	else
		return (ft_puthexa(n / 16, format) + ft_putchar(needed[n % 16]));
}

int	ft_format(va_list args, const char *format)
{
	int	x;

	x = 0;
	if (format[x] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[x] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[x] == 'p')
		return (ft_putaddress(va_arg(args, void *)));
	else if (format[x] == 'd' || format[x] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format[x] == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format[x] == 'x' || format[x] == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), *format));
	else if (format[x] == '%')
		return (ft_putchar('%'));
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
			count += ft_putchar(format[x]);
		x++;
	}
	va_end(args);
	return (count);
}

/*
#include <limits.h>
#include <stdio.h>
int main(void)
{
    int result1;
    int result2;
    result1 = ft_printf(" %p ", 0);
    ft_printf("Characters written: %i\n", result1);
    result2 = printf(" %p ", 0);
    printf("Characters written: %i\n", result2);
    return (0);
}
*/

/*#include <stdio.h>
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
