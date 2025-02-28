NAME = Horde

SRC = Weapon.cpp HumanB.cpp HumanA.cpp  main.cpp 
OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS := -Wall -Werror -Wextra -std=c++98 -g -O3

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

%.d: %.cpp
	$(CC) -M $(CFLAGS) $< > $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re