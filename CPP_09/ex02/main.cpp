#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    // Require at least one input token
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe pm;
        pm.parseArgs(argc, argv); // validates and prepares both containers
        pm.sortAndPrint();        // prints Before/After and timing lines
    }
    catch (const std::exception &)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
