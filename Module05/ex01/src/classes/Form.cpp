#include <Form.hpp>

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute):
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if (gradeToSign < _maxGrade || gradeToExecute < _maxGrade)
		throw GradeTooHighException();
	else if (gradeToSign > _minGrade || gradeToExecute > _minGrade)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form & copy): _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	*this = copy;
}

Form &Form::operator=(Form const & rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << " is ";
	if (!form.getSigned())
		out << "not ";
	out << "signed. Grade to sign: " << form.getGradeToSign() << ". Grade to execute: " << form.getGradeToExecute();
	return out;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}