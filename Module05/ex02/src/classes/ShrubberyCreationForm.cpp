#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy): AForm(copy)
{
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs.getTarget();
	}
	return *this;
}

void ShrubberyCreationForm::executeForm() const
{
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

const std::string &ShrubberyCreationForm::getTarget() const
{
	return _target;
}
