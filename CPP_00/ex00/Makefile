# Program Name
NAME = megaphone

# Compilation
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DEBUG_FLAGS = -g3

# Source and Object Files
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

# Default Target
all: $(NAME)

# Linking the Executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# Compiling Object Files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Debug Build (Optional)
debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

# Run the Program with Examples
run: $(NAME)
	@echo "Example 1:"
	@./$(NAME) "shhhhh... I think the students are asleep..."
	@echo "\nExample 2:"
	@./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@echo "\nExample 3 (No arguments):"
	@./$(NAME)

# Cleaning Object Files
clean:
	$(RM) $(OBJ)

# Cleaning Everything
fclean: clean
	$(RM) $(NAME)

# Rebuild Everything
re: fclean all

# Phony Targets
.PHONY: all clean fclean re debug run
