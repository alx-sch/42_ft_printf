# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 15:16:35 by aschenk           #+#    #+#              #
#    Updated: 2024/01/26 22:57:48 by aschenk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libftprintf.a
CC =			cc
CFLAGS =		-Wall -Wextra -Werror
SRCS =			ft_printf_utils.c ft_printf.c
OBJS =			${SRCS:.c=.o}
LIBFT_SRCS =	$(wildcard libft/*.c)
LIBFT_OBJS =	$(LIBFT_SRCS:.c=.o)

# Target 'all' is the default target, building library specified by $(NAME).
all:	$(NAME)

# Target $(NAME) depends on object files $(OBJS) and libft library.
# Creates libftprintf.a using the .o files in $(OBJS) and in the libft folder.
$(NAME):	$(OBJS) libft/libft.a
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

# Rule to define how to generate object files (%.o) from corresponding
# source files (%.c). Each .o file depends on the associated .c file and the
# libft library header file (libft/libft.h)
# -c:		Generates o. files without linking.
# -o $@:	Output file name;  '$@' is replaced with target name (the o. file).
# -$<:		Represents the first prerequisite (the c. file).
$(OBJS):	%.o: %.c libft/libft.h
	$(CC) $(CFLAGS) -c -o $@ $<

# Build libft library by calling make in the libft directory (-C changes directory).
# This target will be executed if libft.a is missing or if any of the
# .c files in the libft directory are modified.
libft/libft.a: $(LIBFT_SRCS) libft/libft.h
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean:	clean
	make -C libft fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
