#include <iomanip>
#include <sstream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

#define gradeToSignShrubbery 145
#define gradeToExecuteShrubbery 137
#define nameShrubbery "ShrubberyCreation"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	Form(nameShrubbery,
		gradeToSignShrubbery,
		gradeToExecuteShrubbery,
		"Anonymous") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form(nameShrubbery,
		gradeToSignShrubbery,
		gradeToExecuteShrubbery,
		target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) {
	*this = s;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a) {
	Form::operator=(a);
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	Form::execute(executor);
	std::ofstream output;
	output.open(getTarget() + "_shrubbery");
	output << ""
	"                                  .         ;" << std::endl <<
	"     .              .              ;%     ;;" << std::endl <<
	"       ,           ,                :;%  %;" << std::endl <<
	"        :         ;                   :;%;'     .," << std::endl <<
	".        %;     %;            ;        %;'    ,;" << std::endl <<
	" ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl <<
	"  %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl <<
	"   ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl <<
	"    `%;.     ;%;     %;'         `;%%;.%;'" << std::endl <<
	"     `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl <<
	"        `:%;.  :;bd%;          %;@%;'" << std::endl <<
	"          `@%:.  :;%.         ;@@%;'" << std::endl <<
	"            `@%.  `;@%.      ;@@%;" << std::endl <<
	"              `@%%. `@%%    ;@@%;" << std::endl <<
	"                ;@%. :@%%  %@@%;" << std::endl <<
	"                  %@bd%%%bd%%:;" << std::endl <<
	"                    #@%%%%%:;;" << std::endl <<
	"                    %@@%%%::;" << std::endl <<
	"                    %@@@%(o);  ." << std::endl <<
	"                    %@@@o%;:(.,'" << std::endl <<
	"                `.. %@@@o%::;" << std::endl <<
	"                   `)@@@o%::;" << std::endl <<
	"                    %@@(o)::;" << std::endl <<
	"                   .%@@@@%::;" << std::endl <<
	"                   ;%@@@@%::;." << std::endl <<
	"                  ;%@@@@%%:;;;."  << std::endl <<
	"              ...;%@@@@@%%:;;;;,.." << std::endl <<
	std::endl << "Gilo97" << std::endl;
	output.close();
	std::cout << "Shrubbery Form has been executed by " << executor.getName() << std::endl;
}
