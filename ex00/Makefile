NAME=BUREAUCRAT

CXX=c++

CXXFLAGS= -std=c++98 -Wall -Wextra -Werror -fsanitize=address

SRC = Bureaucrat.cpp main.cpp

OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)
fclean:
	@rm -f $(OBJ) $(NAME)
re: fclean clean all