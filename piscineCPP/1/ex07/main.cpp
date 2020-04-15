#include <iostream>
#include <fstream>
#include <string>

int		replaceFirstFoundWord(	std::string *input, 
						std::string s1,
						std::string s2,
						int *i,
						std::size_t *ppos) {
	*ppos = input->find(s1, *ppos);
	if (*ppos != std::string::npos) {
		input->replace(*ppos, s1.length(), s2);
		(*i)++;
		return (1);
	}
	return (0);
}

void	replaceFoundWords(std::string inputFileName,
					std::string s1,
					std::string s2) {
	std::ifstream	inputFile(inputFileName);
	std::string		outputFileName = inputFileName + ".replace";
	std::string		input = "";
	std::string		line = "";
	int				i = 0;
	std::size_t		pos;

	// error case
	if (!inputFile.is_open()) {
		std::cout << "Error: File does not exist. Please enter valid file." << std::endl;
		return ;
	}

	// get the file content in the string named input
	std::ofstream	outputFile(outputFileName);
	while (getline(inputFile, line)) {
		if (i != 0)
			input = input + '\n';
		input += line;
		i++;
	}

	// replace words
	i = 0;
	pos = 0;
	while (replaceFirstFoundWord(&input, s1, s2, &i, &pos));

	// output result in file
	outputFile << input << std::endl;
	outputFile.close();

	// end message
	std::cout << "You've replaced the word [" << s1 << "] with [" << s2 << "] " <<
				i << " times." << std::endl <<
				"The result should be stored in " <<
				outputFileName << std::endl;
}

int 	main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "How to use replace:" << std::endl <<
			"./replace [FILENAME] [WORD TO FIND] [WORD TO REPLACE WITH]" << std::endl;
		return (0);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (s1[0] == '\0' || s2[0] == '\0') {
		std::cout << "Error: One of the word is an empty string. Please enter valid words." << std::endl;
		return (0);
	}
	replaceFoundWords(filename, s1, s2);
}
