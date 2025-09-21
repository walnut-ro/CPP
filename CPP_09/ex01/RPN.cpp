#include "RPN.hpp"

#include <sstream>
#include <stdexcept>
#include <cctype>
#include <climits>

// 64-bit intermediates + range check to detect 32-bit overflow
static inline int add_safe(int a, int b)
{
    long long r = static_cast<long long>(a) + static_cast<long long>(b);
    if (r < INT_MIN || r > INT_MAX)
        throw std::runtime_error("Error");
    return static_cast<int>(r);
}
static inline int sub_safe(int a, int b)
{
    long long r = static_cast<long long>(a) - static_cast<long long>(b);
    if (r < INT_MIN || r > INT_MAX)
        throw std::runtime_error("Error");
    return static_cast<int>(r);
}
static inline int mul_safe(int a, int b)
{
    long long r = static_cast<long long>(a) * static_cast<long long>(b);
    if (r < INT_MIN || r > INT_MAX)
        throw std::runtime_error("Error");
    return static_cast<int>(r);
}

int RPN::applyOperator(int a, int b, char oper)
{
    switch (oper)
    {
    case '+':
        return add_safe(a, b);
    case '-':
        return sub_safe(a, b);
    case '*':
        return mul_safe(a, b);
    case '/':
        if (b == 0)
            throw std::runtime_error("Error");
        // Guard the special overflow case: INT_MIN / -1
        if (a == INT_MIN && b == -1)
            throw std::runtime_error("Error");
        return a / b; // truncates toward zero
    default:
        throw std::runtime_error("Error");
    }
}

int RPN::parseString(const std::string &str)
{
    // reset stack to make the object reusable
    while (!stk_.empty())
        stk_.pop();

    if (str.empty())
        throw std::runtime_error("Error");

    std::istringstream iss(str);
    std::string tok;

    while (iss >> tok)
    {
        if (isOneDigit(tok))
        {
            stk_.push(tok[0] - '0');
        }
        else if (tok.size() == 1 && isOperator(tok[0]))
        {
            if (stk_.size() < 2)
                throw std::runtime_error("Error");
            int b = stk_.top();
            stk_.pop();
            int a = stk_.top();
            stk_.pop();
            stk_.push(applyOperator(a, b, tok[0]));
        }
        else
        {
            // any other token (multi-digit numbers, junk, missing spaces) is invalid
            throw std::runtime_error("Error");
        }
    }

    if (stk_.size() != 1)
        throw std::runtime_error("Error");
    return stk_.top();
}
