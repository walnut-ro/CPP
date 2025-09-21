#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        RPN rpn;
        int res = rpn.parseString(argv[1]);
        std::cout << res << std::endl;
    }
    catch (const std::exception &)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
