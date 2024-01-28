# ====================== VARIABLES ====================== #

# ---- Final executable ---- #
NAME		=	push_swap

# ------------ DIRECTORIES ------------ #

DIR_HEADERS	=	inc/
DIR_SRCS 	=	src/
DIR_LIB		=	lib/
DIR_LIBFT 	=	$(addprefix $(DIR_LIB), libft/)
DIR_OBJS 	=	.objs/

# ------------- SHORTCUTS ------------- #

SRCS			=	$(addprefix $(DIR_SRCS),$(LIST_SRC))
LIBFT			=	$(addprefix $(DIR_LIBFT), libft.a)

# --------------- FILES --------------- #

HEADERS 	= 	${DIR_HEADERS}push_swap.h \
				${DIR_LIBFT}${DIR_HEADERS}libft.h

LIST_SRC        := main.c \
	commands/push.c \
	commands/rev_rotate.c \
	commands/rotate.c \
	commands/swap.c \
	utils/index.c \
	utils/input_check.c \
	utils/utils.c \
	utils/sort_tiny.c \
	utils/radix.c \

OBJS		=	${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

# ------------ COMPILATION ------------ #

CFLAGS 		= 	-Wall -Werror -Wextra -g3
DEP_FLAGS	=	-MMD -MP

# -------------  COMMANDS ------------- #

RM				=	rm -rf

# ====================== RULES ====================== #

.PHONY: all re clean fclean FORCE

# ---------- COMPILED RULES ----------- #

-include $(DEP)

all:			$(NAME)

$(DIR_OBJS)%.o: %.c $(HEADERS)
					mkdir -p $(shell dirname $@)
				    $(CC) $(CFLAGS) $(DEP_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

# ---------- VARIABLES RULES ---------- #

$(NAME): 		$(LIBFT) $(OBJS) $(HEADERS)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(DIR_LIBFT) -lft

$(LIBFT): 		FORCE
				$(MAKE) -C $(DIR_LIBFT)

# ---- Usual rules --- #
clean:
				$(MAKE) -C $(DIR_LIBFT) clean
				$(RM) $(DIR_OBJS)

fclean: clean
				$(RM) $(NAME)
				make fclean -C $(DIR_LIBFT)

re: 			fclean
				$(MAKE) all

FORCE: