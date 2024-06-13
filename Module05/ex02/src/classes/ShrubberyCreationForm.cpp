#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy): AForm(copy)
{
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
	{
		// 
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::ofstream file;
	std::string filename = _target + "_shrubbery";
	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: " << getName() << "could not open file " << filename << std::endl;
		return ;
	}
	std::string tree =
		"       *                   *\n"
        "      ***                 ***\n"
        "     *****               *****\n"
        "    *******             *******\n"
        "   *********           *********\n"
        "  ***********         ***********\n"
        " *************       *************\n"
        "***************     ***************\n"
        "      |||                 |||\n"
        "      |||                 |||\n";
	file << tree;
	file.close();
}