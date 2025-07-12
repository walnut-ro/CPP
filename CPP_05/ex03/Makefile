# Compiler and flags
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

# Executable and files
NAME     = internTest
SRCS     = main.cpp \
           Bureaucrat.cpp \
           AForm.cpp \
           ShrubberyCreationForm.cpp \
           RobotomyRequestForm.cpp \
           PresidentialPardonForm.cpp \
           Intern.cpp

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
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re
