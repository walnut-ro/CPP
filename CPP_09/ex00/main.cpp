#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    // Subject expects exactly one argument: the input file.
    if (argc != 2)
    {
        // Keep the exact wording required by the subject.
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange be;

        // Load the CSV database shipped with the project.
        // parseFile() may throw if the DB file is missing or malformed.
        be.parseFile("data.csv", ',');

        // Process the user-provided input file.
        // calcExchangeRate() prints per-line errors itself and
        // prints "Error: could not open file." if the input cannot be opened.
        be.calcExchangeRate(argv[1], '|');
    }
    catch (const std::exception &e)
    {
        // Print the message as-is. For database issues this will be informative,
        // and it won't interfere with the input-file error messages checked by the subject.
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
