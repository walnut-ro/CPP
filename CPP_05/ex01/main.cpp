#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        std::cout << "----- SIGN FORM TEST -----\n";

        Bureaucrat bob("Bob", 75);
        Bureaucrat alice("Alice", 20);
        Form form("Contract", 50, 100);

        std::cout << "\nInitial state:\n";
        std::cout << "\033[1;33m" << bob << "\033[0m";
        std::cout << "\033[1;33m" << alice << "\033[0m";
        std::cout << "\033[1;35m" << form << "\033[0m";

        std::cout << "\nAttempt: Bob tries to sign (should fail)\n";
        bob.signForm(form);

        std::cout << "\nAttempt: Alice tries to sign (should succeed)\n";
        alice.signForm(form);

        std::cout << "\nAttempt: Alice signs again (should throw AlreadySignedException)\n";
        alice.signForm(form);

        std::cout << "\nFinal state:\n";
        std::cout << "\033[1;35m" << form << "\033[0m";

        std::cout << "---------------------------\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mUnhandled exception: " << e.what() << "\033[0m\n";
    }
    return 0;
}
