SRCS = ft_printf.c ft_itoa.c ft_utoa.c ft_ultoa.c ft_vfprintf.c
OBJS = $(SRCS:.c=.o)
HDRS =

LIBFT = libft

CC = cc
#FLAGS = -Wall -Werror -Wextra
CRTLB = ar rcs


NAME = libftprintf.a

all: $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME)
	$(CRTLB) $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re