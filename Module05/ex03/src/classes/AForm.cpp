#include <AForm.hpp>

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute):
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if (gradeToSign < _maxGrade || gradeToExecute < _maxGrade)
		throw GradeTooHighException();
	else if (gradeToSign > _minGrade || gradeToExecute > _minGrade)
		throw GradeTooLowException();
}

AForm::AForm(const std::string name, const std::string target, int gradeToSign, int gradeToExecute):
	_target(target), _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if (gradeToSign < _maxGrade || gradeToExecute < _maxGrade)
		throw GradeTooHighException();
	else if (gradeToSign > _minGrade || gradeToExecute > _minGrade)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm & copy)
	: _target(copy._target), _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm &AForm::operator=(AForm const & rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return *this;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

std::ostream &operator<<(std::ostream &out, AForm const &Aform)
{
	out << "AForm " << Aform.getName() << " is ";
	if (!Aform.getSigned())
		out << "not ";
	out << "signed. Grade to sign: " << Aform.getGradeToSign() << ". Grade to execute: " << Aform.getGradeToExecute();
	return out;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

