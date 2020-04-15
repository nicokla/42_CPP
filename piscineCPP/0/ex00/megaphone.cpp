#include <iostream>

void	print_capitalize(char *str) {
	int i;
	char c;

	i = 0;
	while (str[i]) {
		c = str[i];
		if (c >= 'a' && c <= 'z')
			c -= 32;			
		std::cout << c;
		i++;
	}
}

int		main(int ac, char **av) {
	int i;

	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	i = 1;
	while (av[i]) {
		print_capitalize(av[i]);
		i++;
	}
	std::cout << std::endl;

	return (0);	
}