
NAME=libft.a

SRC= ft_atoi.c\
     		ft_calloc.c\
     		ft_isalpha.c\
     		ft_isdigit.c\
     		ft_itoa.c\
     		ft_memchr.c\
     		ft_memcpy.c\
     		ft_memset.c\
     		ft_putendl_fd.c\
     		ft_putstr_fd.c\
     		ft_strchr.c\
     		ft_striteri.c\
     		ft_strlcat.c\
     		ft_strlen.c\
     		ft_strncmp.c\
     		ft_strrchr.c\
     		ft_substr.c\
     		ft_toupper.c\
     		ft_bzero.c\
     	   ft_isalnum.c\
     	   ft_isascii.c\
     	   ft_isprint.c\
     	   ft_memcmp.c\
     	   ft_memmove.c\
     	   ft_putchar_fd.c\
     	   ft_putnbr_fd.c\
     	   ft_split.c\
     	   ft_strdup.c\
     	   ft_strjoin.c\
     	   ft_strlcpy.c\
     	   ft_strmapi.c\
     	   ft_strnstr.c\
     	   ft_strtrim.c\
     	   ft_tolower.c

SRCS=$(SRC:%=%)

BONUS_SRCS=ft_lstadd_back_bonus.c\
           			ft_lstclear_bonus.c\
           	  ft_lstiter_bonus.c\
           	  ft_lstmap_bonus.c\
           	  ft_lstsize_bonus.c\
           	  ft_lstadd_front_bonus.c\
           	  ft_lstdelone_bonus.c\
           	  ft_lstlast_bonus.c\
           	  ft_lstnew_bonus.c\

OBJECTS=$(SRCS:.c=.o)

BONUS_OBJS=$(BONUS_SRCS:.c=.o)

ALL_OBJS=$(SRCS:.c=.o) $(BONUS_SRCS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

%.o: %.c  libft/inc/libft.h
	cc -Wall -Wextra -Werror -MMD -MP -c $<

clean:
	rm -f $(ALL_OBJS) $(DEP)

fclean: clean
	rm -f $(NAME)

bonus:
	$(MAKE) $(NAME) SRC="$(SRCS) $(BONUS_SRCS)"

re: fclean all
