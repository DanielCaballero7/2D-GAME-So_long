SRCS	= ft_printf.c ft_printf_utils.c
OBJS	= ${SRCS:.c=.o}
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
CC		= gcc
NAME	= libftprintf.a

all: $(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
