#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);

	AForm *makeForm(const std::string & formName, const std::string & target);
	
	typedef AForm* (*formCreator)(const std::string & target);
private:
	static AForm *createShrubberyCreationForm(const std::string & target);
	static AForm *createRobotomyRequestForm(const std::string & target);
	static AForm *createPresidentialPardonForm(const std::string & target);

	static const formCreator _formCreators[3];
	static const std::string _formNames[3];
};

#endif // INTERN_HPP