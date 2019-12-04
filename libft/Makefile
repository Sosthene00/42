NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

FILES := $(shell find . -name "*.c")
BONUS := $(shell find . -name "ft_lst*.c") 
SRCS := $(filter-out $(BONUS), $(FILES))
OBJS := $(SRCS:.c=.o)
B_OBJS := $(BONUS:.c=.o)
DEPS := ./libft.h 

.PHONY: all clean fclean re

all: $(NAME)

.c.o: 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS) $(B_OBJS)
	ar -rcs $(NAME) $(OBJS) $(B_OBJS)
