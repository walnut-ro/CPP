NAME = animal_program

SRCS = \
	main.cpp \
	Animal.cpp \
	Dog.cpp \
	Cat.cpp \
	Brain.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
