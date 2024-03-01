# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 14:56:58 by jjaroens          #+#    #+#              #
#    Updated: 2024/03/01 16:38:22 by jjaroens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/main.c srcs/push_swap.c srcs/ft_lst_algo.c srcs/ft_lst_utils.c \
	srcs/ft_check_argv_utils.c libft/ft_bzero.c libft/ft_calloc.c \
	libft/ft_strlen.c libft/ft_strlcpy.c libft/ft_split.c

OBJ = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

# .c.o:
# 	cc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) ./libft/libft.a $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f ./libft/libft.a
	rm -f push_swap

re : fclean all

.PHONY: all clean fclean re
