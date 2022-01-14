SRCS = get_next_line.c get_next_line_utils.c main.c
OBJS = $(SRCS:.c=.o)

HDRS = get_next_line.h

CC = gcc
#FLAGS = -Wall -Werror -Wextra
BUFFER_SIZE = 42
CONFIG = -D BUFFER_SIZE=$(BUFFER_SIZE)

 
NAME = get_next_line

all: $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) $(CONFIG) -c $< -o $@
	
$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(CONFIG) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
