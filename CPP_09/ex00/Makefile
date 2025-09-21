NAME := btc

CXX := c++
CXXFLAGS := -std=c++11 -Wall -Wextra -Werror

SRCS := \
  BitcoinExchange.cpp \
  main.cpp

HEADERS := \
  BitcoinExchange.hpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Rebuild objects if any header changes
$(OBJS): $(HEADERS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re