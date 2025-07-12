#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/* Default Constructor */
AForm::AForm() : _name("Basic Form"),
                 _isSigned(false),
                 _gradeToSign(Bureaucrat::c_min_grade),
                 _gradeToExecute(Bureaucrat::c_max_grade)
{
    std::cout << "AForm default constructor called." << std::endl;
}

/* Parameterized Constructor */
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    std::cout << "AForm parameterized constructor called." << std::endl;
    if (gradeToSign < Bureaucrat::c_max_grade || gradeToExecute < Bureaucrat::c_max_grade)
        throw AForm::GradeTooHighException();
    if (gradeToSign > Bureaucrat::c_min_grade || gradeToExecute > Bureaucrat::c_min_grade)
        throw AForm::GradeTooLowException();
}

/* Copy Constructor */
AForm::AForm(const AForm &src) : _name(src._name),
                                 _isSigned(src._isSigned),
                                 _gradeToSign(src._gradeToSign),
                                 _gradeToExecute(src._gradeToExecute)
{
    std::cout << "AForm copy constructor called." << std::endl;
}

/* Destructor */
AForm::~AForm()
{
    std::cout << "AForm destructor called." << std::endl;
}

/* Copy Assignment */
AForm &AForm::operator=(const AForm &src)
{
    std::cout << "AForm copy assignment operator called." << std::endl;
    if (this != &src)
        this->_isSigned = src._isSigned;
    return *this;
}

/* Getters */
std::string AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

/* beSigned logic */
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (_isSigned)
        throw AForm::AlreadySignedException();
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

/* execute() wrapper */
void AForm::execute(const Bureaucrat &executor) const
{
    if (!_isSigned)
        throw AForm::NotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw AForm::GradeTooLowException();
    beExecuted(); // must be implemented in derived class
}

/* Exceptions */
const char *AForm::GradeTooHighException::what() const noexcept
{
    return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const noexcept
{
    return "Grade too low!";
}

const char *AForm::AlreadySignedException::what() const noexcept
{
    return "Form has already been signed!";
}

const char *AForm::NotSignedException::what() const noexcept
{
    return "Form has not been signed yet!";
}

/* Stream output */
std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
    os << "Form \"" << obj.getName() << "\""
       << " [Signed: " << (obj.isSigned() ? "yes" : "no")
       << ", Grade to Sign: " << obj.getGradeToSign()
       << ", Grade to Execute: " << obj.getGradeToExecute()
       << "]" << std::endl;
    return os;
}
