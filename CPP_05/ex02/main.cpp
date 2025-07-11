#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    // === Create Bureaucrats ===
    Bureaucrat lowlyBureaucrat("Lowly Larry", 142);
    Bureaucrat averageBureaucrat("Average Andy", 65);
    Bureaucrat highBureaucrat("High Harry", 6);

    std::cout << "\n=== Bureaucrats ===\n";
    std::cout << lowlyBureaucrat;
    std::cout << averageBureaucrat;
    std::cout << highBureaucrat << "\n";

    // === Create Forms ===
    ShrubberyCreationForm shrubForm("Forest");
    RobotomyRequestForm robotomyForm("CEO");
    PresidentialPardonForm pardonForm(highBureaucrat.getName());

    std::cout << "\n=== Forms ===\n";
    std::cout << shrubForm;
    std::cout << robotomyForm;
    std::cout << pardonForm;

    // === Shrubbery ===
    std::cout << "\n=== Shrubbery form ===\n";
    lowlyBureaucrat.signForm(shrubForm);
    lowlyBureaucrat.executeForm(shrubForm);   // too low
    averageBureaucrat.executeForm(shrubForm); // OK

    // === Pardon ===
    std::cout << "\n=== Presidential Pardon form ===\n";
    highBureaucrat.executeForm(pardonForm); // not signed
    highBureaucrat.signForm(pardonForm);
    highBureaucrat.executeForm(pardonForm); // OK
    highBureaucrat.incrementGrade();        // grade becomes 5
    highBureaucrat.executeForm(pardonForm); // still OK

    // === Robotomy ===
    std::cout << "\n=== Robotomy form ===\n";
    averageBureaucrat.executeForm(robotomyForm); // not signed
    averageBureaucrat.signForm(robotomyForm);
    averageBureaucrat.executeForm(robotomyForm); // random success
    highBureaucrat.executeForm(robotomyForm);    // also allowed

    // === Additional edge case tests ===
    std::cout << "\n=== Additional Tests ===\n";

    // 1. Повторная подпись
    std::cout << "\n--- Double-sign test ---\n";
    averageBureaucrat.signForm(shrubForm); // already signed

    // 2. Повторное выполнение robotomy
    std::cout << "\n--- Re-execute robotomy form ---\n";
    averageBureaucrat.executeForm(robotomyForm);

    // 3. Недостаточный grade
    Bureaucrat tooLow("Intern", 149);
    ShrubberyCreationForm hardForm("Jungle");

    std::cout << "\n--- Too low to sign or execute ---\n";
    tooLow.signForm(hardForm);
    tooLow.executeForm(hardForm);

    // 4. Copy and assignment
    std::cout << "\n--- Copy constructor and assignment ---\n";
    ShrubberyCreationForm copyForm(shrubForm);
    ShrubberyCreationForm assignedForm;
    assignedForm = shrubForm;

    std::cout << "Copy:     " << copyForm;
    std::cout << "Assigned: " << assignedForm;

    // 5. Пустой target
    std::cout << "\n--- Empty target test ---\n";
    RobotomyRequestForm badTargetForm("");
    averageBureaucrat.signForm(badTargetForm);
    averageBureaucrat.executeForm(badTargetForm);

    // 6. Границы grade
    std::cout << "\n--- Grade boundaries ---\n";
    try
    {
        Bureaucrat max("MAX", 1);
        std::cout << max;
    }
    catch (const std::exception &e)
    {
        std::cerr << "MAX Bureaucrat error: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat min("MIN", 150);
        std::cout << min;
    }
    catch (const std::exception &e)
    {
        std::cerr << "MIN Bureaucrat error: " << e.what() << std::endl;
    }

    return 0;
}
