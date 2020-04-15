#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

class ImpossibleException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Impossible";
		};
};

class NonDisplayableException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Non displayable";
		};
};

int getPrecision(char *s) {
	unsigned int i = 0;
	unsigned int j;
	while (s[i] != 0 && s[i] != '.') {
		i++;
	}
	if (strlen(s) == i) {
		return 1;
	}
	j = i + 1;
	while (s[j] != 0 && isdigit(s[j])) {
		j++;
	}
	j -= i;
	if (j == 1) {
		return 1;
	} else {
		return (j - 1);
	}
}

void printChar(char *s) {
	double d = atof(s);
	try {
		char c;
		std::cout << "char: ";
		if (isnan(d))
			throw ImpossibleException();
		c = static_cast<char>(d);
		if (!std::isprint(c))
			throw NonDisplayableException();
		std::cout << "'" << c << "'" << std::endl;
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void printInt(char *s) {
	double d = atof(s);
	try {
		int i;
		std::cout << "int: ";
		if (isinf(d) || isnan(d) || (d > static_cast<int>(INT_MAX))
			|| (d < static_cast<int>(INT_MIN))) {
			throw ImpossibleException();
		}
		i = static_cast<int>(d);
		std::cout << i << std::endl;
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void printFloat(char *s) {
	int p = getPrecision(s);
	double d = atof(s);
	std::cout << "float: " << std::setprecision(p) << std::fixed << static_cast<float>(d) << "f" << std::endl;
}

void printDouble(char *s) {
	int p = getPrecision(s);
	double d = atof(s);
	std::cout << "double: " << std::setprecision(p) << std::fixed << static_cast<double>(d) << std::endl;	
}

int main(int ac, char* av[]) {
	(void)ac;
	for (int i = 1; av[i] != NULL; i++) {
		std::cout << "string : " << av[i] << std::endl;
		printChar(av[i]);
		printInt(av[i]);
		printFloat(av[i]);
		printDouble(av[i]);
		if (av[i+1])
			std::cout << std::endl;
	}
	return 0;
}
