#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

// Default constructor
Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    std::cout << "Bureaucrat default constructor called\n";
}

// Parametrized constructor
Bureaucrat::Bureaucrat(const std::string &in_name, int grade) : name(in_name)
{
    std::cout << "Bureaucrat parametrized constructor called\n";
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : name(rhs.getName()), grade(rhs.getGrade())
{
    std::cout << "Bureaucrat copy constructor called\n";
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called\n";
}

// Copy assignment
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    std::cout << "Bureaucrat assignment operator called\n";
    if (this != &rhs)
        this->grade = rhs.getGrade(); // name is const
    return *this;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    ++grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    --grade;
}

// Exceptions with modern C++ (C++11+)
const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade too low";
}

// Operator <<
std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << '\n';
    return o;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << '\n';
    }
}
