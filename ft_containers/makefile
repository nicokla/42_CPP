NAME	= a.out
SRC		= main.cpp 
CFLAG	= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(CFLAG) $(SRC) $^ -o $(NAME)

diff:
	@diff list.ft.res list.std.res

%.o: %.cpp
	clang++ -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test