#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));

    std::cout << "----- Example from subject -----\n";
    Span sp(5);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 2
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;  // 14
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "----- Test with addRange (1000 numbers) -----\n";
    try
    {
        Span arr(1000);
        std::vector<int> tmp(1000);
        for (size_t i = 0; i < tmp.size(); i++)
            tmp[i] = std::rand();
        arr.addRange(tmp.begin(), tmp.end());

        std::cout << "Shortest span: " << arr.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << arr.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "----- Test with too few elements -----\n";
    Span minArr(1);
    try
    {
        minArr.addNumber(std::rand());
        std::cout << "Shortest span: " << minArr.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << minArr.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "----- Test with overflow -----\n";
    try
    {
        Span small(3);
        small.addNumber(10);
        small.addNumber(20);
        small.addNumber(30);
        std::cout << "Trying to add one more...\n";
        small.addNumber(40); // должно вызвать исключение
    }
    catch (const std::exception &e)
    {
        std::cout << "Overflow error: " << e.what() << std::endl;
    }

    return 0;
}
