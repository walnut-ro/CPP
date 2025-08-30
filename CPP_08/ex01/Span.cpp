#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : _max(0), _v() {}

Span::Span(unsigned int N) : _max(N), _v() {}

Span::Span(const Span &copy) : _max(copy._max), _v(copy._v) {}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        _max = copy._max;
        _v = copy._v;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_v.size() >= _max)
        throw std::overflow_error("Span is full, cannot add more numbers.");
    _v.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_v.size() < 2)
        throw std::logic_error("Not enough elements to find a span.");

    std::vector<int> sorted(_v);
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        if (diff < minSpan)
            minSpan = diff;
        if (minSpan == 0)
            break; // быстрее не бывает
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_v.size() < 2)
        throw std::logic_error("Not enough elements to find a span.");

    int minVal = *std::min_element(_v.begin(), _v.end());
    int maxVal = *std::max_element(_v.begin(), _v.end());
    return static_cast<unsigned int>(maxVal - minVal);
}
