#include "Intern.hpp"
#include <iostream>

/* Constructor */
Intern::Intern()
{
    // Инициализация массивов имен и указателей на методы
    formNames[0] = "shrubbery creation";
    formNames[1] = "robotomy request";
    formNames[2] = "presidential pardon";

    creators[0] = &Intern::createShrubbery;
    creators[1] = &Intern::createRobotomy;
    creators[2] = &Intern::createPresidential;
}

/* Destructor */
Intern::~Intern() {}

/* Copy constructor */
Intern::Intern(const Intern &copy)
{
    *this = copy;
}

/* Assignment operator */
Intern &Intern::operator=(const Intern &)
{
    // Nothing to copy in this case (stateless class)
    return *this;
}

/* Exception class */
const char *Intern::FormNotFoundException::what() const noexcept
{
    return "Intern: Form not found";
}

/* Form creators */
AForm *Intern::createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

/* Factory */
AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    for (int i = 0; i < 3; ++i)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates \"" << formName << "\" form." << std::endl;
            return (this->*creators[i])(target);
        }
    }
    throw FormNotFoundException();
}
