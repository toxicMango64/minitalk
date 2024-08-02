NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -g3 -O2
CFILES = 	ft_printf.c \
			ft_char.c \
			ft_hexa.c \
			ft_nbr.c \
			ft_ptr.c \
			ft_perr.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME) : $(OFILES)
	ar -rcs $(NAME) $(OFILES)

clean:
	rm -fr $(OFILES) *.out

fclean:clean
	rm -fr $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
