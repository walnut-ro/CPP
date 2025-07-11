# Compiler and flags
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

# Executable and source files
NAME     = formtest
SRCS     = main.cpp Bureaucrat.cpp Form.cpp
OBJS     = $(SRCS:.cpp=.o)

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

# Phony targets
.PHONY: all clean fclean re
