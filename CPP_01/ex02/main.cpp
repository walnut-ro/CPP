#include <iostream>
#include <string>

int main()
{
    // String variable
    std::string brain = "HI THIS IS BRAIN";

    // Pointer to the string
    std::string *stringPTR = &brain;

    // Reference to the string
    std::string &stringREF = brain;

    // Output memory addresses
    std::cout << "Memory address of the string variable: " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    // Output string values
    std::cout << "Value of the string variable: " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
