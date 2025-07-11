#include "Bureaucrat.hpp"
#include <iostream>

void testBureaucrat(const std::string &name, int grade, bool change = false, bool increment = true, int steps = 1)
{
    std::cout << "---------------------------\n";
    try
    {
        Bureaucrat b(name, grade);
        std::cout << "\033[1;32mYES: " << b << "\033[0m";

        if (change)
        {
            for (int i = 0; i < steps; ++i)
            {
                if (increment)
                    b.incrementGrade();
                else
                    b.decrementGrade();
            }
            std::cout << "\033[1;32mYES (after change): " << b << "\033[0m";
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mNO: " << name << ": " << e.what() << "\033[0m\n";
    }
}

int main()
{
    testBureaucrat("Lower", 150);
    testBureaucrat("Higher", 1);
    testBureaucrat("Lower than necessary", 151);
    testBureaucrat("Higher than necessary", 0);
    testBureaucrat("Medium", 75);

    testBureaucrat("Lower-1", 150, true, false); // попытка увеличить grade > 150
    testBureaucrat("Higher+1", 1, true, true);   // попытка уменьшить grade < 1

    testBureaucrat("Higher-1", 1, true, false); // понижение grade с 1 до 2
    testBureaucrat("Lower+1", 150, true, true); // повышение grade с 150 до 149

    testBureaucrat("Medium-10", 75, true, false, 10);
    testBureaucrat("Medium+10", 75, true, true, 10);

    std::cout << "---------------------------\n";
    return 0;
}
