NAME        = serializer
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++20

SRCS        = main.cpp Serializer.cpp
OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re