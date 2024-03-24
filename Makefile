# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 14:56:58 by jjaroens          #+#    #+#              #
#    Updated: 2024/03/24 17:36:57 by jjaroens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/main.c srcs/push_swap.c srcs/ft_lst_algo.c srcs/ft_lst_utils.c \
		srcs/ft_check_argv_utils.c 

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
