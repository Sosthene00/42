NAME = cube3d.out
BONUS_NAME = cube3d_bonus.out
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

FILES := $(shell find . -maxdepth 1 -name "*.c")
BONUS := $(shell find . -maxdepth 1 -name "*_bonus.c") 
SRCS := $(filter-out $(BONUS), $(FILES))
OBJS := $(SRCS:.c=.o)
B_OBJS := $(BONUS:.c=.o)
DEPS = ./cube3d.h 
MLXDIR = mlx/ 
LIBFTDIR = libft/
FRAMEWORK = -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $@ $(SRCS) -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx $(FRAMEWORK)

clean:
	$(RM) $(OBJS) $(B_OBJS)
	make clean -C $(LIBFTDIR)
	make clean -C $(MLXDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(SRCS) -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx $(FRAMEWORK)
