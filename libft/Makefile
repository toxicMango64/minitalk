NAME	=	libft.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
CFILES	=	./ft_atoi.c \
			./ft_isdigit.c \
			./ft_itoa.c \
			./ft_printf/ft_char.c \
			./ft_printf/ft_hexa.c \
			./ft_printf/ft_nbr.c \
			./ft_printf/ft_perr.c \
			./ft_printf/ft_printf.c \
			./ft_printf/ft_ptr.c \
			./ft_strlen.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME) : $(OFILES)
	@ar -rcs $(NAME) *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr *.o

fclean:clean
	@rm -fr $(NAME)
	rm -fr *.o

re: fclean $(NAME)

.PHONY: all clean fclean re
