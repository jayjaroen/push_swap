NAME = cub3d

MLX_DIR = minilibx
LIB_DIR = libft
SRC_DIR = srcs
HEADER = srcs/push_swap.h
INCLUDES = 	-I$(LIB_DIR) \
			-I$(SRC_DIR)
			
LINK_LIB = -L$(LIB_DIR) -lft

CC = cc
# CFLAGS = -Wall -Werror -Wextra $(INCLUDES) -g -fsanitize=address
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)

SRCS = main_test.c

OBJS = $(SRCS:.c=.o) 

all: $(NAME)

# $(NAME): $(OBJS) $(HEADER) Makefile
# 	$(MAKE) -C $(LIB_DIR)
# 	$(CC) $(CFLAGS) $(LINK_LIB) $(OBJS) -o $(NAME)

$(NAME): $(HEADER) Makefile
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(LINK_LIB) $(SRCS) -o $(NAME)

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(LIB_DIR)/libft.a
	rm -rf $(NAME)

l:
	leaks --atExit -- ./$(NAME) $(MAP)

# v:
# 	valgrind --leak-check=full ./$(NAME) $(MAP)

m:
	./$(NAME) $(MAP)

norminette:
	@norminette -R CheckForbiddenSourceHeader $(LIB_DIR)/*.c
	@norminette -R CheckDefine $(LIB_DIR)/includes/libft.h
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)
	@norminette -R CheckDefine $(SRC_DIR)/cub3d.h

re: fclean all

.PHONY: all clean fclean re