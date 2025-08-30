#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    std::cout << "=== ex00: easyfind tests ===\n";

    // --- vector ---
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);
    try
    {
        std::cout << "Found in vector: " << *easyfind(v, 5) << "\n";
        std::cout << "Found in vector: " << *easyfind(v, 42) << "\n"; // fail
    }
    catch (const std::exception &e)
    {
        std::cout << "Vector error: " << e.what() << "\n";
    }

    // --- list ---
    std::list<int> lst;
    for (int i = 10; i < 15; ++i)
        lst.push_back(i);
    try
    {
        std::cout << "Found in list: " << *easyfind(lst, 13) << "\n";
        std::cout << "Found in list: " << *easyfind(lst, 99) << "\n"; // fail
    }
    catch (const std::exception &e)
    {
        std::cout << "List error: " << e.what() << "\n";
    }

    // --- deque ---
    std::deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);
    dq.push_back(300);
    try
    {
        std::cout << "Found in deque: " << *easyfind(dq, 200) << "\n";
        std::cout << "Found in deque: " << *easyfind(dq, -1) << "\n"; // fail
    }
    catch (const std::exception &e)
    {
        std::cout << "Deque error: " << e.what() << "\n";
    }

    // --- duplicates test ---
    std::vector<int> dup;
    dup.push_back(5);
    dup.push_back(10);
    dup.push_back(5);
    dup.push_back(20);
    try
    {
        std::vector<int>::iterator it = easyfind(dup, 5);
        std::cout << "First 5 found in dup vector: index "
                  << (it - dup.begin()) << ", value = " << *it << "\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Duplicates test error: " << e.what() << "\n";
    }

    // --- const container test ---
    const std::vector<int> cv = {1, 2, 3, 4, 5};
    try
    {
        std::vector<int>::const_iterator it = easyfind(cv, 4);
        std::cout << "Found in const vector: " << *it << "\n";
        it = easyfind(cv, 99); // fail
        std::cout << "Found in const vector: " << *it << "\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Const vector error: " << e.what() << "\n";
    }

    return 0;
}
