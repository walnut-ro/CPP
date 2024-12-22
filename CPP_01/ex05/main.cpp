#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "Calling DEBUG:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "Calling INFO:" << std::endl;
    harl.complain("INFO");

    std::cout << "Calling WARNING:" << std::endl;
    harl.complain("WARNING");

    std::cout << "Calling ERROR:" << std::endl;
    harl.complain("ERROR");

    std::cout << "Calling INVALID LEVEL:" << std::endl;
    harl.complain("INVALID");

    return 0;
}
