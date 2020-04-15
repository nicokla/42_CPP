
NAME	= a.out
SRC		= main.cpp \
			AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
CFLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(CFLAG) $(SRC) $^ -o $(NAME)

%.o: %.cpp
	clang++ -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test
