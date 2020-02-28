NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS := $(shell find . -name "*.c")
OBJS := $(SRCS:.c=.o)
DEPS := ./libft.h 

.PHONY: all clean fclean re

all: $(NAME)

.c.o: 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
