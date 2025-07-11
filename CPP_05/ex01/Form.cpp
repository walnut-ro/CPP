#include "Form.hpp"
#include <iostream>

// Exception classes

const char *Form::GradeTooHighException::what() const noexcept
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const noexcept
{
    return "Grade is too low";
}

const char *Form::AlreadySignedException::what() const noexcept
{
    return "The form has already been signed";
}

// Constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    else if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

// Destructor
Form::~Form() {}

// Copy constructor
Form::Form(const Form &copy)
    : _name(copy._name),
      _isSigned(copy._isSigned),
      _gradeToSign(copy._gradeToSign),
      _gradeToExecute(copy._gradeToExecute) {}

// Copy assignment
Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
        // Остальные поля const и не копируются
    }
    return *this;
}

// Getters
std::string Form::getName() const
{
    return _name;
}

bool Form::getSignatureStatus() const
{
    return _isSigned;
}

int Form::getGradeSign() const
{
    return _gradeToSign;
}

int Form::getGradeExecute() const
{
    return _gradeToExecute;
}

// Main logic
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (_isSigned)
        throw AlreadySignedException();
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Stream output
std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << "Form state:\n"
       << "  Name: " << obj.getName() << '\n'
       << "  Signed: " << std::boolalpha << obj.getSignatureStatus() << '\n'
       << "  Grade required to sign: " << obj.getGradeSign() << '\n'
       << "  Grade required to execute: " << obj.getGradeExecute() << '\n';
    return os;
}
