/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:13:24 by aschenk           #+#    #+#             */
/*   Updated: 2024/06/24 21:14:29 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
When located in the root directory, compile the test program:
-	'make' to generate libftprintf.a
-	(optional: 'make clean' for cleanup)
-	'cc -o test test_ft_printf.c libftprintf.a' to compile the test program
-	'./test' to run it.
*/

#include <stdio.h> // printf()
#include <unistd.h> // usleep()
#include "ft_printf.h"

#define BOLD	"\033[1m"
#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define RESET	"\033[0m"

static void	check_return_values(int res1, int res2)
{
	if (res1 == res2)
		printf(GREEN BOLD "OK!\n\n" RESET);
	else
		printf(RED BOLD"FAIL!\n\n" RESET);
}

int	main(void)
{
	int		length_my_fct;
	int		length_native;
	char	*ptr;
	char	str[] = "Hello World!!";
	int		nbr;
	char	c;

	ptr = str;
	nbr = 42133742;
	c = 'z';

	// Testing w/o any format specificer
	printf(BOLD "\n== TESTING: No Format Specificer ==\n\n" RESET);

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("Test string!");
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("Test string!");
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing empty string
	printf(BOLD "== TESTING: Empty Format String ==\n\n" RESET);

	printf("-- ft_printf() --");
	length_my_fct = ft_printf("");
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --");
	length_native = printf("");
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing %c
	printf(BOLD "== TESTING: %%c ==\n\n" RESET);

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("Printing char->%c", c);
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("Printing char->%c", c);
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing %%
	printf(BOLD "== TESTING: %%%% ==\n\n" RESET);

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("This project is 100%% correct!");
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("This project is 100%% correct!");
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing %s
	printf(BOLD "== TESTING: %%s ==\n\n" RESET);

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("Printing a string->%s", str);
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("Printing a string->%s", str);
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing %s NULL string
	printf(BOLD "== TESTING: %%s NULL String ==\n\n" RESET);

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("Printing a string->%s", (char *)NULL);
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("Printing a string->%s", (char *)NULL);
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing %d
	printf(BOLD "== TESTING: %%d ==\n\n" RESET);

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("Printing a decimal number->%d", nbr);
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("Printing a decimal number->%d", nbr);
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing %i
	printf(BOLD "== TESTING: %%i ==\n\n" RESET);

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("Printing an integer base 10 "
			"(same as decimal)->%i", nbr);
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("Printing an integer base 10 "
			"(same as decimal)->%i", nbr);
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing %u
	printf(BOLD "== TESTING: %%u ==\n\n" RESET);

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("Printing %d as unsinged->%u",
			nbr * (-1), nbr * (-1));
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("Printing %d as unsinged->%u",
			nbr * (-1), nbr * (-1));
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing %p
	printf(BOLD "== TESTING: %%p ==\n\n" RESET);

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("Printing pointer->%p", (void *)ptr);
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("Printing pointer->%p", (void *)ptr);
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing %p null pointer
	printf(BOLD "== TESTING: %%p NULL Pointer ==\n\n" RESET);

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("Printing pointer->%p", (void*)NULL);
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("Printing pointer->%p", (void*)NULL);
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing %x %X
	printf(BOLD "== TESTING: %%x/%%X ==\n\n" RESET);

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("Printing %d as hex->%x\n", nbr, nbr);
	ft_printf("Printing %d as HEX->%X", nbr, nbr);
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("Printing %d as hex->%x\n", nbr, nbr);
	printf("Printing %d as HEX->%X", nbr, nbr);
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing % at EOF
	printf(BOLD "== TESTING: %% at EOF ==\n" RESET);
	printf("Undefined behavior! printf() result/printout depends on OS!\n\n" );

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("%% at EOF->%");
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("%% at EOF->%");
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing space after %
	printf(BOLD "== TESTING: Only Spaces after %% ==\n" RESET);
	printf("Undefined behavior! printf() result/printout depends on OS!\n\n" );

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("->%   ");
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("->%   ");
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);

	// Testing undefined specifier
	printf(BOLD "== TESTING: Undefined specifier ==\n" RESET);
	printf("Undefined behavior! printf() result/printout depends on OS!\n\n" );

	printf("-- ft_printf() --\n");
	length_my_fct = ft_printf("->%k");
	printf("\nReturn value: %d\n\n", length_my_fct);

	printf("-- printf() --\n");
	length_native = printf("->%k");
	printf("\nReturn value: %d\n\n", length_native);

	check_return_values(length_my_fct, length_native);


	return (0);
}
