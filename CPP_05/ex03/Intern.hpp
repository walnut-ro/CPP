#pragma once

#include <string>
#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    ~Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);

    AForm *makeForm(const std::string &formName, const std::string &target);

    class FormNotFoundException : public std::exception
    {
    public:
        const char *what() const noexcept override;
    };

private:
    // Формы для поиска
    std::string formNames[3];
    AForm *(Intern::*creators[3])(const std::string &target);

    // Реализация создания каждой формы
    AForm *createShrubbery(const std::string &target);
    AForm *createRobotomy(const std::string &target);
    AForm *createPresidential(const std::string &target);
};
