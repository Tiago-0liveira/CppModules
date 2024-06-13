#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	if (grade < _maxGrade)
		throw GradeTooHighException();
	else if (grade > _minGrade)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat & copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
	{
		_grade = rhs._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == _maxGrade)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == _minGrade)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned())
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because it's already signed" << std::endl;
		return;
	}
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
	} catch (AForm::GradeTooLowException &e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
		return;
	} catch (AForm::FormNotSignedException &e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
