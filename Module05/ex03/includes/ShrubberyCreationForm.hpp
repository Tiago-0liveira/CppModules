#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <AForm.hpp>

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm(const std::string& target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm & copy);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const & rhs);
	
	void executeForm() const;
	const std::string &getTarget() const;
private:
	std::string _target;
};

#endif // SHRUBBERYCREATIONFORM_HPP