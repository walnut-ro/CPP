#pragma once

#include <stack>
#include <string>

class RPN
{
private:
    std::stack<int> stk_; // evaluation stack

public:
    RPN() = default;
    ~RPN() = default;
    RPN(const RPN &) = default;
    RPN &operator=(const RPN &) = default;

    // Parse and evaluate a space-separated RPN expression.
    // Returns the integer result, throws std::runtime_error("Error") on any invalid input.
    int parseString(const std::string &str);

private:
    // Apply binary operator (a oper b); throws std::runtime_error("Error") on error/overflow/div0.
    int applyOperator(int a, int b, char oper);

    static bool isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }
    static bool isOneDigit(const std::string &tok)
    {
        return tok.size() == 1 && tok[0] >= '0' && tok[0] <= '9';
    }
};