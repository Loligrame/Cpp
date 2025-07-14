NAME = Serializer

SRC = Serializer.cpp main.cpp
OBJ_DIR =  obj/
OBJ = $(SRC:.cpp=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

CC = c++
CFLAGS := -Wall -Werror -Wextra -std=c++98 -g -O3

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

%.d: %.cpp
	$(CC) -M $(CFLAGS) $< > $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re