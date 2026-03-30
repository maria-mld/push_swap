NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinc -Ilibft

ifdef SAN
	CFLAGS += -fsanitize=address
endif

LIBFT_DIR   = libft/
LIBFT       = $(LIBFT_DIR)libft.a

SRC_DIR     = src/
OBJ_DIR     = obj/

SRC_FILES   = main.c \
              stack_init.c \
              stack_utils.c \
              operations/push.c \
              operations/rev_rotate.c \
              operations/rotate.c \
              operations/swap.c \
              sort/move_nodes.c \
              sort/init_a_to_b.c \
              sort/sort_utils.c \
			  sort/turk_sort.c \
              sort/init_b_to_a.c

SRCS        = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS        = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(LIBFT) $(NAME)


$(LIBFT):
	@make -C $(LIBFT_DIR) $(if $(SAN),SAN=1)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "push_swap compiled with Libft!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "Objects removed."

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "Binary and Libft removed."

re: fclean all

.PHONY: all clean fclean re