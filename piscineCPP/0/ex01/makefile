
NAME	= phonebook
SRC		= main.cpp Contact.cpp Phonebook.cpp
CFLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang++ $(CFLAG) $(SRC) -I . -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test
