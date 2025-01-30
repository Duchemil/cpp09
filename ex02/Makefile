CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET   = RPN
SRC      = main.cpp RPN.cpp
OBJ      = $(SRC:.cpp=.o)

all: $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
