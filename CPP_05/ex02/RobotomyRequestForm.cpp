#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/* Default Constructor */
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExecute),
      _target("Unknown")
{
    std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

/* Copy Constructor */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), _target(src._target)
{
    std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

/* Parameterized Constructor */
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request Form", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExecute),
      _target(target.empty() ? "Unknown" : target)
{
    std::cout << "RobotomyRequestForm target constructor called." << std::endl;
}

/* Destructor */
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

/* Copy assignment operator */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    std::cout << "RobotomyRequestForm copy assignment operator called." << std::endl;
    if (this != &src)
        this->_target = src._target;
    return *this;
}

/* Accessor */
const std::string &RobotomyRequestForm::getTarget() const
{
    return _target;
}

/* beExecuted — logic for execution */
void RobotomyRequestForm::beExecuted() const
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // seed rand once per execution

    std::cout << "* drilling noises * BZZZZZZZ... 🛠️" << std::endl;

    if (std::rand() % 2)
    {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
    }
}
