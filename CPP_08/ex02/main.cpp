#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main()
{
    std::cout << "----- MutantStack basic test -----\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(77);
    mstack.push(24);
    mstack.push(400);
    mstack.push(0);

    std::cout << "Iterating MutantStack from bottom to top:\n";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "Iterating MutantStack in reverse (top to bottom):\n";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << std::endl;

    std::cout << "Copy to std::stack and print top->bottom:\n";
    std::stack<int> s(mstack);
    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    std::cout << "----- Comparison with std::list -----\n";
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "Top element in list: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "Size after pop_back: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(77);
    lst.push_back(24);
    lst.push_back(400);
    lst.push_back(0);

    std::cout << "Iterating list from begin to end:\n";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}
