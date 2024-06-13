#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy): AForm(copy)
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
	{
		// 
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::srand(std::time(0));
	int random = std::rand() % 2;
	std::cout << "*drilling noises*" << std::endl;
	std::cout << random << std::endl;
	if (random == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomization of " << _target << " has failed" << std::endl;
}