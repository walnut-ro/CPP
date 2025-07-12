#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Intern Form Creation Test ===\n"
              << std::endl;

    Intern intern;

    // Создание валидных форм
    try
    {
        std::cout << "// Test: Create ShrubberyCreationForm\n";
        AForm *shrubbery = intern.makeForm("shrubbery creation", "Garden");
        std::cout << *shrubbery << std::endl;
        delete shrubbery;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception during shrubbery form creation: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "// Test: Create RobotomyRequestForm\n";
        AForm *robotomy = intern.makeForm("robotomy request", "Marvin");
        std::cout << *robotomy << std::endl;
        delete robotomy;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception during robotomy form creation: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "// Test: Create PresidentialPardonForm\n";
        AForm *pardon = intern.makeForm("presidential pardon", "Arthur Dent");
        std::cout << *pardon << std::endl;
        delete pardon;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception during presidential form creation: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Form Creation Test ===\n"
              << std::endl;

    // Попытка создать несуществующую форму
    try
    {
        std::cout << "// Test: Create invalid form\n";
        AForm *invalid = intern.makeForm("invalid form", "Nobody");
        delete invalid;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Done ===" << std::endl;
    return 0;
}
