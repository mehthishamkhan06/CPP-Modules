# Variables
CXX     = c++
FLAGS  = -Wall -Wextra -Werror -std=c++98
SRC    = MegaPhone.cpp
OBJ    = $(SRC:.cpp=.o)
NAME   = MegaPhone


all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re