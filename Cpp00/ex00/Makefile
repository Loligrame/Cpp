NAME = megaphone

SRC = megaphone.cpp\

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = c++
CFLAGS := -Wall -Werror -Wextra -std=c++98

RM = rm -f

all: $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


$(NAME): $(OBJ) $(LIBFT_FILE) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FILE) -o $(NAME) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_FILE):
	@make -C $(LIBFT_DIR)

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re