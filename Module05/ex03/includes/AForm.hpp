#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <Bureaucrat.hpp>

class Bureaucrat;

class AForm
{
public:
	virtual ~AForm();
	AForm(const AForm & copy);
	AForm &operator=(AForm const & rhs);

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
	class FormNotSignedException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	std::string getName() const;
	bool getSigned() const;	
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);
	void execute(Bureaucrat const & executor) const;
	virtual void executeForm() const = 0;
protected:
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _signed;

	static int const _maxGrade = 1;
	static int const _minGrade = 150;
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif // AFORM_HPP