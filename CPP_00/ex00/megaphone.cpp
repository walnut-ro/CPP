#include <iostream> // For std::cout
#include <cctype>   // For std::toupper
#include <cstring>  // For strlen

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        for (size_t j = 0; j < std::strlen(argv[i]); j++)
        {
            std::cout << static_cast<char>(std::toupper(argv[i][j]));
        }
    }
    std::cout << std::endl;
    return 0;
}
