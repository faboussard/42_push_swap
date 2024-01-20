NAME        := push_swap

LIBFT_H     := libft/inc/libft.h
LIBFT       := libft/libft.a
INC         := inc/
SRC_DIR     := srcs/
OBJ_DIR     := obj/

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g3
RM          := rm -f

SRCS        := src/commands/push.c \
	src/commands/rev_rotate.c \
	src/commands/rotate.c \
	src/commands/swap.c \
	src/utils/index.c \
	src/utils/input_check.c \
	src/utils/utils.c \
	src/utils/sort_tiny.c \
	src/utils/radix.c \
	src/push_swap.c

all:   mylibft \
		$(NAME)

OBJ:= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC) $(LIBFT) $(LIBFT)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT_H) $(INC)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

mylibft:
		make -C ./libft

clean:
		$(RM) -r $(OBJ_DIR)
		make clean -C ./libft

fclean: clean
		$(RM) $(NAME)
		make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re mylibft
