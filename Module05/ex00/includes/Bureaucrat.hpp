#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat & copy);
	Bureaucrat &operator=(Bureaucrat const & rhs);

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

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
private:
	const std::string _name;
	int _grade;

	static int const _maxGrade = 1;
	static int const _minGrade = 150;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif // Bureaucrat_HPP