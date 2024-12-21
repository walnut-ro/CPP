NAME = phonebook
TEST_NAME = test_phonebook

# Compilation
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)

TEST_SRC = test_phonebook.cpp PhoneBook.cpp Contact.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

all: $(NAME)

# Build the main executable
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Build Successful: $(NAME)"

# Build and run the test
test: $(TEST_OBJ)
	@$(CC) $(CFLAGS) $(TEST_OBJ) -o $(TEST_NAME)
	@echo "Running tests..."
	./$(TEST_NAME)
	@rm -f $(TEST_OBJ) $(TEST_NAME)
	@echo "Test completed and cleaned up."

# Compile object files
%.o: %.cpp
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJ)
	@echo "Objects cleaned."

# Clean everything (including test executable and main executable)
fclean: clean
	@rm -f $(NAME) $(TEST_NAME)
	@echo "All executables removed."

# Rebuild everything
re: fclean all

.PHONY: all test clean fclean re
