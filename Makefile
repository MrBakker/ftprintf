NAME = libftprintf.a

CC := cc
DIR := objs/
EXTRAFLAGS := -Wall -Wextra -Werror

SRCS := ft_printf.c ft_printf_utils.c ft_putstr.c ft_putchar.c \
	ft_putvoidptr.c ft_putnum.c ft_putunum.c ft_printhex.c ft_flags.c \
	ft_write.c

BINS := $(addprefix ${DIR}, ${SRCS:.c=.o})

all: ${NAME}

${NAME}: ${BINS}
	@ar r ${NAME} ${BINS}

${DIR}%.o: %.c ft_printf.h
	@mkdir -p ${DIR}
	@${CC} ${EXTRAFLAGS} -c $< -o $@

clean:
	@rm -rf ${DIR}

fclean: clean
	@rm -f ${NAME}

bonus: all

re: fclean all

.PHONY: all bonus clean fclean re