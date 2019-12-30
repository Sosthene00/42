NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

FILES := $(shell find . -name "*.c")
BONUS := $(shell find . -name "*_bonus.c") 
SRCS := $(filter-out $(BONUS), $(FILES))
OBJS := $(SRCS:.c=.o)
B_OBJS := $(BONUS:.c=.o)
DEPS := ./ft_printf.h 

.PHONY: all clean fclean re

all: $(NAME)

.c.o: 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) libft
	ar -rcs $@ $(OBJS)

libft: 
	$(MAKE) -C libft/

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS) $(B_OBJS)
	ar -rcs $(NAME) $(OBJS) $(B_OBJS)
