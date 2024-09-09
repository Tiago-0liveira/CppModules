#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <AForm.hpp>

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm(const std::string target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm & copy);
	RobotomyRequestForm &operator=(RobotomyRequestForm const & rhs);

	virtual void execute(Bureaucrat const & executor) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP