/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:13:24 by aschenk           #+#    #+#             */
/*   Updated: 2024/01/27 01:19:48 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
When located in the root directory, compile the test program:
-	'make' to generate libftprintf.a
-	(optional: 'make clean' for cleanup)
-	'cc -o test test_ft_printf.c libftprintf.a' to compile the test program
-	'./test' to run it.
*/

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		length_my_fct;
	int		length_native;
	char	*ptr;
	char	str[] = "Hello World!!";
	int		nbr;
	int		neg_nbr;

	ptr = str;
	nbr = 42133742;
	neg_nbr = -424242;

	// Testing w/o any format specificer
	printf("\n== TESTING: No Format Specificer ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("No formatters to be found!\n"); ////////
	printf("Return value: %d\n", length_my_fct);
	length_native = printf("No formatters to be found!\n"); ////////
	printf("Return value: %d\n", length_native);

	// Testing empty string
	printf("\n== TESTING: printf('') ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf(""); ////////
	printf("\nReturn value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf(""); ////////
	printf("\nReturn value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %c
	printf("== TESTING: %%c ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("Printing a char: %c\n", 'z'); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing a char: %c\n", 'z'); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %%
	printf("== TESTING: %%%% ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("This project is 100%% correct!\n"); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("This project is 100%% correct!\n"); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %s
	printf("== TESTING: %%s ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("Printing a string: %s\n", str); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing a string: %s\n", str); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %s NULL string
	printf("== TESTING: %%s NULL string ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("Printing a string: %s\n", (char *)NULL); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing a string: %s\n", (char *)NULL); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %d
	printf("== TESTING: %%d ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("Printing a decimal number: %d\n", nbr); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing a decimal number: %d\n", nbr); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %i
	printf("== TESTING: %%i ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("Printing an integer base 10 "
		"(same as decimal): %i\n", nbr); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing an integer base 10 "
		"(same as decimal): %i\n", nbr); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %u
	printf("== TESTING: %%u ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("Printing %d as unsinged: %u\n", ////
		neg_nbr, neg_nbr); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing %d as unsinged: %u\n", ////
		neg_nbr, neg_nbr); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %p
	printf("== TESTING: %%p ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("Printing pointer: %p\n", (void *)ptr); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing pointer: %p\n", (void *)ptr); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %p null pointer
	ptr = NULL;
	printf("== TESTING: %%p (null pointer)==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("Printing pointer: %p\n", (void*)ptr); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing pointer: %p\n", (void*)ptr); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing %x %X
	printf("== TESTING: %%x/%%X ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("Printing %d as hex: %x\n", nbr, nbr); ////////
	ft_printf("Printing %d as HEX: %X\n", nbr, nbr); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing %d as hex: %x\n", nbr, nbr); ////////
	printf("Printing %d as HEX: %X\n", nbr, nbr); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing invalid specifier
	printf("== TESTING: invalid specifier ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("Printing out specifier %%k: %k\n", nbr); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("Printing out specifier %%k: %k\n", nbr); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing % at EOF
	printf("== TESTING: %% at EOF ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("%% at EOF->%"); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("%% at EOF->%"); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// Testing whitespace after %
	printf("== TESTING: only whitespace after %% ==\n");
	printf("-- ft_printf(): --\n");
	length_my_fct = ft_printf("%% end: % 	\n"); ////////
	printf("Return value: %d\n", length_my_fct);

	printf("-- printf(): --\n");
	length_native = printf("%% end: % 	\n"); ////////
	printf("Return value: %d\n", length_native);
	printf("\n============\n\n");

	// // Testing multiple ' ' between % and non-exisingt specifier
	// printf("== TESTING: Multiple ' ' between %% and non-existing specifier ==\n");
	// printf("-- ft_printf(): --\n");
	// length_my_fct = ft_printf("%% here->%   !\n"); ////////
	// printf("Return value: %d\n", length_my_fct);

	// printf("-- printf(): --\n");
	// length_native = printf("%% here->%   !\n"); ////////
	// printf("Return value: %d\n", length_native);
	// printf("\n============\n\n");

	return (0);
}
