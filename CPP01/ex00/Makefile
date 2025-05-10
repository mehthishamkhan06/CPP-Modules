CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98
NAME        := BraiiiiiiinnnzzzZ
SRCS        := main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJS        := $(SRCS:.cpp=.o)

# Colors
GREEN       := \033[1;32m
BLUE        := \033[1;34m


all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)🔧 Linking object files into executable..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@echo "$(GREEN)📦 Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(BLUE)🧹 Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)🧹 Executable cleaned."

re: fclean all
