#include "iter.hpp"
#include <string>

int main()
{
    float arr[] = {0.2f, 0.5f, 1.5f, 2.5f};

    std::cout << "Original float array:" << std::endl;
    printArray(arr, 4);

    iter(arr, 4, plusFloat);

    std::cout << "Modified float array:" << std::endl;
    printArray(arr, 4);

    std::string str[] = {"Jim", "Jack", "Jon"};

    std::cout << "Original string array:" << std::endl;
    printArray(str, 3);

    iter(str, 3, prependHello);

    std::cout << "Modified string array:" << std::endl;
    printArray(str, 3);

    return 0;
}
