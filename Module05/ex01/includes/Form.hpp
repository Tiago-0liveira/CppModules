#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <Bureaucrat.hpp>

class Bureaucrat;

class Form
{
public:
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(const Form & copy);
	Form &operator=(Form const & rhs);

	class GradeTooHighException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	std::string getName() const;
	bool getSigned() const;	
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);
private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _signed;

	static int const _maxGrade = 1;
	static int const _minGrade = 150;
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif // FORM_HPP