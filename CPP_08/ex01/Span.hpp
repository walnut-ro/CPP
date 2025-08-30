#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
    unsigned int _max;
    std::vector<int> _v;

public:
    // Orthodox Canonical Form
    Span();
    Span(unsigned int N);
    Span(const Span &copy);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);

    template <typename InputIt>
    void addRange(InputIt first, InputIt last)
    {
        if (_v.size() + std::distance(first, last) > _max)
            throw std::overflow_error("Span is full");
        _v.insert(_v.end(), first, last);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
};
