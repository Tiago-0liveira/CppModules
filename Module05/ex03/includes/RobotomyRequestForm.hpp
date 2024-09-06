#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <AForm.hpp>

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm(const std::string& target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm & copy);
	RobotomyRequestForm &operator=(RobotomyRequestForm const & rhs);
	
	void executeForm() const;
	const std::string &getTarget() const;
private:
	std::string _target;
};

#endif // ROBOTOMYREQUESTFORM_HPP