NAME = a.out  # Change this to 'a.out' if you want the output file to be named 'a.out'
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)  # Add include path for libft
LIBFT_DIR = ./libft
LIBS = -L$(LIBFT_DIR) -lft

# Source files for pushswap
PUSH_SWAP_SRCS = main.c utils.c utils1.c utils2.c
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
