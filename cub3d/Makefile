NAME = cub3d
BONUS_NAME = cub3d_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g 
DEBUG = -fsanitize=address
RM = rm -f
SRC_DIR = ./src
OBJ_DIR = ./obj

FILES := $(notdir $(shell find $(SRC_DIR) -name "*.c"))
BONUS := $(notdir $(shell find $(SRC_DIR) -name "*_bonus.c"))
SRC := $(filter-out $(BONUS),$(FILES))
OBJ := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
B_OBJ := $(addprefix $(OBJ_DIR)/,$(BONUS:.c=.o))
INC_DIR = ./includes
MLXDIR = ./mlx_linux/ 
LIBFTDIR = ./libft/

.PHONY: all clean fclean re re_all re_bonus clean_all fclean_libft bonus nuke

all: $(NAME)
bonus: $(BONUS_NAME) | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c

	$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(MLXDIR) -I$(INC_DIR) -o $@ -c $<

$(NAME): | $(OBJ_DIR) $(OBJ)
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	#$(CC) $(CFLAGS) $(DEBUG) -o $@ $(OBJ) -L$(LIBFTDIR) -L$(MLXDIR) -I$(INC_DIR) -lft -lm -lmlx -lX11 -lXext  
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFTDIR) -L$(MLXDIR) -I$(INC_DIR) -lft -lm -lmlx -lX11 -lXext  

$(BONUS_NAME): | $(OBJ_DIR) $(B_OBJ)
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $@ $(B_OBJ) -L$(LIBFTDIR) -L$(MLXDIR) -I$(INC_DIR) -lft -lm -lmlx -lX11 -lXext

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

clean_all: 
	make -C $(LIBFTDIR) clean
	make -C $(MLXDIR) clean

fclean_libft: clean_all
	make -C $(LIBFTDIR) fclean

nuke: fclean clean_all fclean_libft

re: fclean all

re_bonus: fclean bonus

re_all: fclean_libft clean_all fclean all 
