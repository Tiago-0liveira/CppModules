#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <AForm.hpp>

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm(const std::string target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm & copy);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const & rhs);

	virtual void execute(Bureaucrat const & executor) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP