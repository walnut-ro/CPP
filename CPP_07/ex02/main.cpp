#include "Array.hpp"
#include <iostream>
#include <exception>

int main()
{
    // Create and fill an int array
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i + 20;
    }

    std::cout << "Int Array:" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl
              << std::endl;

    // Out of bounds test
    std::cout << "OUT OF BOUNDS" << std::endl;
    try
    {
        std::cout << intArray[7] << std::endl; // invalid
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl
                  << std::endl;
    }

    // Copy constructor test
    std::cout << "COPY CONSTRUCTOR" << std::endl;
    Array<int> copyArray(intArray);
    copyArray[0] = 42;

    std::cout << "Copy Array:" << std::endl;
    for (unsigned int i = 0; i < copyArray.size(); i++)
    {
        std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "Original Array after copy:" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl
              << std::endl;

    // Const array test
    const Array<int> &constArr = intArray;
    std::cout << "Elements of const array:" << std::endl;
    for (unsigned int i = 0; i < constArr.size(); i++)
    {
        std::cout << constArr[i] << " "; // works (read-only)
    }
    std::cout << std::endl
              << std::endl;

    // Uncomment to check compile-time error:
    // constArr[0] = 100; // ❌ should fail (read-only)

    // Non-const reference test
    Array<int> &nonconstArr = intArray;
    nonconstArr[0] = 100;
    std::cout << "Elements of non-const array (after modification):" << std::endl;
    for (unsigned int i = 0; i < nonconstArr.size(); i++)
    {
        std::cout << nonconstArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib> // for rand(), srand()
#include <ctime>   // for time()

#define MAX_VAL 750

int main()
{
    // ==== INT ARRAY TEST ====
    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];

    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // SCOPE: test copy constructor and assignment operator
    {
        Array<int> tmp = numbers; // assignment
        Array<int> test(tmp);     // copy constructor
    }

    // Validate data integrity
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "ERROR: values differ!" << std::endl;
            delete[] mirror;
            return 1;
        }
    }

    // Out-of-bounds tests
    std::cout << "OUT OF BOUNDS TESTS:" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Modify values again
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    delete[] mirror; // cleanup raw array

    // ==== STRING ARRAY TEST ====
    std::cout << "\n=== STRING ARRAY TEST ===" << std::endl;

    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "C++";
    words[2] = "Templates";

    std::cout << "Original words array: ";
    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << words[i] << " ";
    std::cout << std::endl;

    // Deep copy check
    Array<std::string> copyWords(words);
    words[0] = "Modified";

    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original: ";
    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << words[i] << " ";
    std::cout << std::endl;

    std::cout << "Copy:     ";
    for (unsigned int i = 0; i < copyWords.size(); i++)
        std::cout << copyWords[i] << " ";
    std::cout << std::endl;

    // Out-of-bounds with strings
    try
    {
        std::cout << words[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
*/