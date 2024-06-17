#include <Intern.hpp>

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &other)
{
	(void)other;
}
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm *Intern::createShrubberyCreationForm(const std::string & target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string & target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string & target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string & formName, const std::string & target)
{
	for (int i = 0; i < 3; i++)
	{
		if (formName == _formNames[i])
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return _formCreators[i](target);
		}
	}
	std::cout << "Invalid form name!" << std::endl;
	return NULL;
}

const Intern::formCreator Intern::_formCreators[3] = {
    &Intern::createShrubberyCreationForm,
    &Intern::createRobotomyRequestForm,
    &Intern::createPresidentialPardonForm
};

const std::string Intern::_formNames[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};