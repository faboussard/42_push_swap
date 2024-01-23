# ====================== VARIABLES ====================== #

# ---- Final executable ---- #
NAME		=	push_swap

LIBFT		=	libft/libft.a

# ---- Directories ---- #
DIR_HEADERS	=	inc/
DIR_SRCS 	=	src/
DIR_LIBFT 	=	libft/
DIR_OBJS 	=	.objs/

# ---- Files path ---- #
HEADERS 	= 	${DIR_HEADERS}push_swap.h \
				${DIR_LIBFT}${DIR_HEADERS}libft.h

SRCS        := $(DIR_SRCS)main.c \
	$(DIR_SRCS)commands/push.c \
	$(DIR_SRCS)commands/rev_rotate.c \
	$(DIR_SRCS)commands/rotate.c \
	$(DIR_SRCS)commands/swap.c \
	$(DIR_SRCS)utils/index.c \
	$(DIR_SRCS)utils/input_check.c \
	$(DIR_SRCS)utils/utils.c \
	$(DIR_SRCS)utils/sort_tiny.c \
	$(DIR_SRCS)utils/radix.c \

OBJS		=	${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

# ---- Flag ---- #
CFLAGS 		= 	-Wall -Werror -Wextra -g3

# ====================== RULES ====================== #

.PHONY: all re clean fclean FORCE

# ---- Compiled rules ---- #
all:			${NAME}

${DIR_OBJS}%.o: %.c ${HEADERS} Makefile
				@ mkdir -p ${shell dirname $@}
				${CC} ${CFLAGS} -c $< -o $@

${NAME}: 		${LIBFT} ${OBJS} ${HEADERS}
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${DIR_OBJS}:
				mkdir -p ${DIR_OBJS}

${LIBFT}: 		FORCE
				${MAKE} -C ${DIR_LIBFT}

# ---- Usual rules --- #
clean:
				make fclean -C ${DIR_LIBFT}
				${RM} -rf ${DIR_OBJS}

fclean:			clean
				${RM} ${NAME}
				make fclean -C ${DIR_LIBFT}

re: 			fclean all

FORCE: