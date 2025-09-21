#pragma once

#include <vector>
#include <deque>
#include <string>
#include <chrono>

// No 'using namespace' per subject rules.
class PmergeMe
{
private:
    // Original input to print "Before:"
    std::vector<unsigned int> original_;

    // Containers to sort independently
    std::vector<unsigned int> vec_;
    std::deque<unsigned int> deq_;

    // Timings (adding + sorting)
    std::chrono::microseconds timeAddVector_;
    std::chrono::microseconds timeAddDeque_;
    std::chrono::microseconds timeSortVector_;
    std::chrono::microseconds timeSortDeque_;

public:
    PmergeMe();
    ~PmergeMe();

    // Parse all argv tokens (supports multiple args and quoted strings with spaces).
    // Validates strictly: only [0-9]+, range 1..INT_MAX. On any error throws std::runtime_error("Error").
    void parseArgs(int argc, char **argv);

    // Run Ford–Johnson on both containers, print Before/After and timing lines.
    void sortAndPrint();

private:
    // ---- Ford–Johnson for vector ----
    std::vector<unsigned int> fordJohnsonVector(const std::vector<unsigned int> &arr) const;

    // ---- Ford–Johnson for deque ----
    std::deque<unsigned int> fordJohnsonDeque(const std::deque<unsigned int> &arr) const;

    // Jacobsthal helpers
    static unsigned long long jacobsthal(unsigned long long k);
    static std::vector<std::size_t> buildInsertionSequence(std::size_t m_pairs);

    // Tokenization & validation
    static void tokenizeArg(const std::string &arg, std::vector<std::string> &outTokens);
    static unsigned int parsePositive(const std::string &tok); // throws "Error" on failure

    // Utility to print a range in one line ("Before:" / "After:")
    template <typename It>
    static void printLine(const char *prefix, It first, It last);
};
