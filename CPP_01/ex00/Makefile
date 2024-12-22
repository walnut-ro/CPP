# Compiler and flags
CXX       := c++
CXXFLAGS  := -Wall -Wextra -Werror -std=c++11

# Target name
NAME      := zombie

# Source files
SRCS      := main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS      := $(SRCS:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
