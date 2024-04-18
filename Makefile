# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 14:56:58 by jjaroens          #+#    #+#              #
#    Updated: 2024/04/18 12:00:24 by jjaroens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/main.c srcs/push_swap.c srcs/ft_operations.c srcs/ft_node_utils.c \
		srcs/ft_check_argv_utils.c srcs/ft_sorting_stack.c \
		srcs/ft_stack_utils.c srcs/ft_print_output.c srcs/ft_finding_utils.c \
		srcs/ft_init_stack.c srcs/ft_init_stack_utils.c \
		srcs/ft_moving_between_stacks.c srcs/ft_moving_between_stacks_2.c \
		srcs/ft_find_best_match.c

LIBFT = ./libft/libft.a

INCLUDE = include

HEADER = $(INCLUDE)/push_swap.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(OBJS): %.o: %.c $(HEADER)
	cc $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f ./libft/libft.a
	rm -f push_swap

norminette:
	@norminette -R CheckForbiddenSourceHeader srcs/*.c
	@norminette -R CheckForbiddenSourceHeader libft/*.c
	@norminette -R CheckDefine libft/libft.h
	@norminette -R CheckDefine $(INCLUDE)/*.h
# .PHONY: all clean fclean re
