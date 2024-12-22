#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Replace all occurrences of 's1' in 'line' with 's2'.
 *
 * @param line The string to process.
 * @param s1 The string to replace.
 * @param s2 The replacement string.
 * @return std::string The processed string.
 */
std::string replaceAll(const std::string &line, const std::string &s1, const std::string &s2)
{
    if (s1.empty())
    {
        return line; // If s1 is empty, do nothing
    }

    std::string result;
    size_t pos = 0;
    size_t prev = 0;

    // Find and replace all occurrences of s1
    while ((pos = line.find(s1, prev)) != std::string::npos)
    {
        result += line.substr(prev, pos - prev); // Append text before s1
        result += s2;                            // Append s2
        prev = pos + s1.length();                // Move past s1
    }
    result += line.substr(prev); // Append the remaining part of the line
    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Open input file
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    // Open output file
    std::ofstream outputFile(filename + ".replace");
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create file " << filename << ".replace" << std::endl;
        inputFile.close();
        return 1;
    }

    // Process the file line by line
    std::string line;
    while (std::getline(inputFile, line))
    {
        outputFile << replaceAll(line, s1, s2) << std::endl;
    }

    // Close files
    inputFile.close();
    outputFile.close();

    return 0;
}
