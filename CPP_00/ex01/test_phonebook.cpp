#include <cstdlib>
#include <iostream>
#include <fstream>

int main()
{
    // File paths for test input and output
    const char *inputFile = "test_input.txt";
    const char *outputFile = "test_output.txt";

    // Create test input file
    std::ofstream testInput(inputFile);
    if (!testInput)
    {
        std::cerr << "Error: Unable to create input file\n";
        return 1;
    }

    // Add contacts sequentially and display state
    for (int i = 1; i <= 9; i++)
    {
        testInput << "1\n";                                  // Add contact
        testInput << "First" << i << "\n";                   // First Name
        testInput << "Last" << i << "\n";                    // Last Name
        testInput << "Nick" << i << "\n";                    // Nickname
        testInput << "12345678" << i << "\n";                // Phone Number
        testInput << "Secret" << i << "\n";                  // Darkest Secret
        testInput << "2\n";                                  // Search contacts
        testInput << ((i % 8 == 0) ? 7 : i % 8 - 1) << "\n"; // View the contact just added
    }

    // Exit program
    testInput << "3\n"; // Exit
    testInput.close();

    // Run the phonebook program with input redirection
    std::string command = "./phonebook < ";
    command += inputFile;
    command += " > ";
    command += outputFile;
    int result = std::system(command.c_str());

    // Check the execution result
    if (result != 0)
    {
        std::cerr << "Error: Failed to execute ./phonebook\n";
        return 1;
    }

    // Display program output
    std::ifstream testOutput(outputFile);
    if (!testOutput)
    {
        std::cerr << "Error: Unable to open output file\n";
        return 1;
    }

    std::cout << "Program output:\n";
    std::cout << testOutput.rdbuf();
    testOutput.close();

    // Clean up temporary files
    std::remove(inputFile);
    std::remove(outputFile);

    return 0;
}
