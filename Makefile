NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR)
LIBFT_DIR = ./libft
LIBS = -L$(LIBFT_DIR) -lft

# Source files for pushswap
PUSH_SWAP_SRCS = main.c helpers.c helpers2.c sorting.c errors.c ./commands/push.c ./commands/rev_rotate.c init_a_to_b.c init_b_to_a.c ./commands/swap.c sort_stacks.c ./commands/rotate.c helpers3.c
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

# 'all' target
all: $(NAME)

$(NAME): libft $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(LIBS) -o $(NAME)

# Compile libft
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Pattern rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 'clean' rule
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(PUSH_SWAP_OBJS)

# 'fclean' rule
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# 're' rule
re: fclean all

# Declare phony targets
.PHONY: all libft clean fclean re
