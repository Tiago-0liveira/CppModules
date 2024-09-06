#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <AForm.hpp>

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm(const std::string& target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm & copy);
	PresidentialPardonForm &operator=(PresidentialPardonForm const & rhs);

	void executeForm() const;
	const std::string &getTarget() const;
private:
	std::string _target;
};

#endif // PRESIDENTIALPARDONFORM_HPP