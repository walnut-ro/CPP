#include "PresidentialPardonForm.hpp"
#include <iostream>

/* Default Constructor */
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExecute),
      _target("Unknown")
{
    std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

/* Copy Constructor */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src), _target(src._target)
{
    std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

/* Parameterized Constructor */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon Form", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExecute),
      _target(target.empty() ? "Unknown" : target)
{
    std::cout << "PresidentialPardonForm target constructor called." << std::endl;
}

/* Destructor */
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

/* Copy assignment operator */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    std::cout << "PresidentialPardonForm copy assignment operator called." << std::endl;
    if (this != &src)
        this->_target = src._target;
    return *this;
}

/* Accessor */
const std::string &PresidentialPardonForm::getTarget() const
{
    return _target;
}

/* beExecuted — Message from subject */
void PresidentialPardonForm::beExecuted() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
