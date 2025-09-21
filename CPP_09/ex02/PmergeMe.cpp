#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map> // for id -> pair lookup
#include <utility>

// ---------- Ctor/Dtor ----------
PmergeMe::PmergeMe()
    : timeAddVector_(0), timeAddDeque_(0), timeSortVector_(0), timeSortDeque_(0)
{
}

PmergeMe::~PmergeMe() {}

// ---------- Tokenization & validation ----------

void PmergeMe::tokenizeArg(const std::string &arg, std::vector<std::string> &outTokens)
{
    std::istringstream iss(arg);
    std::string t;
    while (iss >> t)
        outTokens.push_back(t);
}

unsigned int PmergeMe::parsePositive(const std::string &tok)
{
    if (tok.empty())
        throw std::runtime_error("Error");
    // Only digits allowed
    for (std::size_t i = 0; i < tok.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(tok[i])))
        {
            throw std::runtime_error("Error");
        }
    }
    // Parse as unsigned long long and clamp to 1..INT_MAX
    char *endp = NULL;
    unsigned long long v = std::strtoull(tok.c_str(), &endp, 10);
    if (endp == tok.c_str() || *endp != '\0')
        throw std::runtime_error("Error");
    if (v == 0ull || v > static_cast<unsigned long long>(INT_MAX))
        throw std::runtime_error("Error");
    return static_cast<unsigned int>(v);
}

// ---------- Jacobsthal sequence helpers ----------

unsigned long long PmergeMe::jacobsthal(unsigned long long k)
{
    // J(0)=0, J(1)=1, J(k)=J(k-1)+2*J(k-2)
    if (k == 0ull)
        return 0ull;
    if (k == 1ull)
        return 1ull;
    unsigned long long a = 0ull, b = 1ull;
    for (unsigned long long i = 2ull; i <= k; ++i)
    {
        unsigned long long next = b + 2ull * a;
        a = b;
        b = next;
    }
    return b;
}

std::vector<std::size_t> PmergeMe::buildInsertionSequence(std::size_t m_pairs)
{
    // Build indices i in the order: J(k) .. J(k-1)+1 (descending), for k=2,3,..., until J(k-1) >= m
    // Indices are 1-based over pairs (i in [1..m]). We will skip i=1 here because b1 inserted separately.
    std::vector<std::size_t> seq;
    if (m_pairs <= 1)
        return seq;
    std::size_t k = 2;
    for (;;)
    {
        std::size_t j = static_cast<std::size_t>(jacobsthal(k));
        std::size_t jprev = static_cast<std::size_t>(jacobsthal(k - 1));
        if (jprev >= m_pairs)
            break;
        std::size_t upper = std::min(j, m_pairs);
        for (std::size_t i = upper; i > jprev; --i)
        {
            if (i >= 2 && i <= m_pairs)
                seq.push_back(i); // i=2..m
        }
        ++k;
    }
    return seq;
}

// ---------- parseArgs ----------

void PmergeMe::parseArgs(int argc, char **argv)
{
    original_.clear();
    vec_.clear();
    deq_.clear();

    if (argc < 2)
        throw std::runtime_error("Error");

    // Collect tokens from all argv
    std::vector<std::string> tokens;
    tokens.reserve(static_cast<std::size_t>(argc - 1));
    for (int i = 1; i < argc; ++i)
    {
        tokenizeArg(std::string(argv[i]), tokens);
    }
    if (tokens.empty())
        throw std::runtime_error("Error");

    // Parse once to a temp vector (so both containers get identical data)
    std::vector<unsigned int> values;
    values.reserve(tokens.size());
    for (std::size_t i = 0; i < tokens.size(); ++i)
    {
        values.push_back(parsePositive(tokens[i])); // throws "Error" on any invalid token
    }

    // Time: adding to vector
    {
        const std::chrono::high_resolution_clock::time_point t0 = std::chrono::high_resolution_clock::now();
        vec_.insert(vec_.end(), values.begin(), values.end());
        const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        timeAddVector_ = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    }

    // Time: adding to deque
    {
        const std::chrono::high_resolution_clock::time_point t0 = std::chrono::high_resolution_clock::now();
        for (std::size_t i = 0; i < values.size(); ++i)
            deq_.push_back(values[i]);
        const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        timeAddDeque_ = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    }

    // Save original (for "Before:")
    original_ = values;
}

// ---------- Utility print ----------

template <typename It>
void PmergeMe::printLine(const char *prefix, It first, It last)
{
    std::cout << prefix;
    for (It it = first; it != last; ++it)
    {
        std::cout << *it;
        if (it + 1 != last)
            std::cout << ' ';
    }
    std::cout << std::endl;
}

// ---------- Ford–Johnson core (vector version) ----------

std::vector<unsigned int> PmergeMe::fordJohnsonVector(const std::vector<unsigned int> &arr) const
{
    const std::size_t n = arr.size();
    if (n <= 1)
        return arr;

    // Build pairs (max, min) with ids 0..m-1
    struct Pair
    {
        unsigned int a_max;
        unsigned int b_min;
        std::size_t id;
    };
    std::vector<Pair> pairs;
    pairs.reserve(n / 2);
    for (std::size_t i = 0; i + 1 < n; i += 2)
    {
        unsigned int x = arr[i], y = arr[i + 1];
        if (x >= y)
            pairs.push_back(Pair{x, y, pairs.size()});
        else
            pairs.push_back(Pair{y, x, pairs.size()});
    }
    const std::size_t m = pairs.size();

    // Recursively sort the 'a' values (maxima) using Ford–Johnson itself (values only)
    std::vector<unsigned int> a_vals;
    a_vals.reserve(m);
    for (std::size_t i = 0; i < m; ++i)
        a_vals.push_back(pairs[i].a_max);
    a_vals = fordJohnsonVector(a_vals);

    // Map a_max value -> queue of ids of pairs that have this a_max (to handle duplicates)
    std::map<unsigned int, std::deque<std::size_t>> by_value_ids;
    for (std::size_t i = 0; i < m; ++i)
    {
        by_value_ids[pairs[i].a_max].push_back(pairs[i].id);
    }

    // main_chain holds both a's (with their ids) and inserted b's (id not used afterwards)
    struct Node
    {
        unsigned int value;
        std::size_t id;
        bool isA;
    };
    std::vector<Node> main_chain;
    main_chain.reserve(n);
    // Push a's in sorted order and resolve ids deterministically
    for (std::size_t i = 0; i < a_vals.size(); ++i)
    {
        unsigned int v = a_vals[i];
        std::size_t id = by_value_ids[v].front();
        by_value_ids[v].pop_front();
        main_chain.push_back(Node{v, id, true});
    }

    // Insert b1 (partner of the first a in main_chain) at the beginning
    if (!pairs.empty())
    {
        const std::size_t id_a1 = main_chain.front().id;
        const unsigned int b1 = pairs[id_a1].b_min;
        main_chain.insert(main_chain.begin(), Node{b1, static_cast<std::size_t>(-1), false});
    }

    // Build Jacobsthal insertion order for i in [2..m]
    std::vector<std::size_t> seq = buildInsertionSequence(m);
    // Insert each b_i before its partner a_i (binary search on [begin, pos(a_i)))
    for (std::size_t idx = 0; idx < seq.size(); ++idx)
    {
        std::size_t i = seq[idx];         // 1-based pair index
        const std::size_t pairId = i - 1; // 0-based id
        const unsigned int b_i = pairs[pairId].b_min;

        // Find current position of a_i by id in main_chain
        std::size_t posA = 0;
        for (; posA < main_chain.size(); ++posA)
        {
            if (main_chain[posA].isA && main_chain[posA].id == pairId)
                break;
        }
        // Binary search in [begin, begin+posA)
        std::vector<Node>::iterator ub = main_chain.begin() + static_cast<std::ptrdiff_t>(posA);
        std::vector<Node>::iterator lb = std::lower_bound(
            main_chain.begin(), ub, b_i,
            [](const Node &node, unsigned int value)
            { return node.value < value; });
        main_chain.insert(lb, Node{b_i, static_cast<std::size_t>(-1), false});
    }

    // Odd tail element (if n is odd) — insert into full range
    if (n % 2 != 0)
    {
        const unsigned int tail = arr.back();
        std::vector<Node>::iterator lb = std::lower_bound(
            main_chain.begin(), main_chain.end(), tail,
            [](const Node &node, unsigned int value)
            { return node.value < value; });
        main_chain.insert(lb, Node{tail, static_cast<std::size_t>(-1), false});
    }

    // Extract values
    std::vector<unsigned int> result;
    result.reserve(main_chain.size());
    for (std::size_t i = 0; i < main_chain.size(); ++i)
        result.push_back(main_chain[i].value);
    return result;
}

// ---------- Ford–Johnson core (deque version) ----------

std::deque<unsigned int> PmergeMe::fordJohnsonDeque(const std::deque<unsigned int> &arr) const
{
    const std::size_t n = arr.size();
    if (n <= 1)
        return arr;

    struct Pair
    {
        unsigned int a_max;
        unsigned int b_min;
        std::size_t id;
    };
    std::vector<Pair> pairs;
    pairs.reserve(n / 2);
    for (std::size_t i = 0; i + 1 < n; i += 2)
    {
        unsigned int x = arr[i], y = arr[i + 1];
        if (x >= y)
            pairs.push_back(Pair{x, y, pairs.size()});
        else
            pairs.push_back(Pair{y, x, pairs.size()});
    }
    const std::size_t m = pairs.size();

    // Sort a's recursively via vector implementation (values only)
    std::vector<unsigned int> a_vals;
    a_vals.reserve(m);
    for (std::size_t i = 0; i < m; ++i)
        a_vals.push_back(pairs[i].a_max);
    a_vals = fordJohnsonVector(a_vals);

    // value -> ids map
    std::map<unsigned int, std::deque<std::size_t>> by_value_ids;
    for (std::size_t i = 0; i < m; ++i)
    {
        by_value_ids[pairs[i].a_max].push_back(pairs[i].id);
    }

    struct Node
    {
        unsigned int value;
        std::size_t id;
        bool isA;
    };
    std::deque<Node> main_chain;
    main_chain.clear();

    for (std::size_t i = 0; i < a_vals.size(); ++i)
    {
        unsigned int v = a_vals[i];
        std::size_t id = by_value_ids[v].front();
        by_value_ids[v].pop_front();
        main_chain.push_back(Node{v, id, true});
    }

    if (!pairs.empty())
    {
        const std::size_t id_a1 = main_chain.front().id;
        const unsigned int b1 = pairs[id_a1].b_min;
        main_chain.push_front(Node{b1, static_cast<std::size_t>(-1), false});
    }

    std::vector<std::size_t> seq = buildInsertionSequence(m);
    for (std::size_t idx = 0; idx < seq.size(); ++idx)
    {
        std::size_t i = seq[idx];
        const std::size_t pairId = i - 1;
        const unsigned int b_i = pairs[pairId].b_min;

        // Find pos of a_i by id
        std::size_t posA = 0;
        for (; posA < main_chain.size(); ++posA)
        {
            if (main_chain[posA].isA && main_chain[posA].id == pairId)
                break;
        }
        // lower_bound in [begin, begin+posA)
        std::deque<Node>::iterator ub = main_chain.begin() + static_cast<std::ptrdiff_t>(posA);
        std::deque<Node>::iterator lb = std::lower_bound(
            main_chain.begin(), ub, b_i,
            [](const Node &node, unsigned int value)
            { return node.value < value; });
        main_chain.insert(lb, Node{b_i, static_cast<std::size_t>(-1), false});
    }

    if (n % 2 != 0)
    {
        const unsigned int tail = arr.back();
        std::deque<Node>::iterator lb = std::lower_bound(
            main_chain.begin(), main_chain.end(), tail,
            [](const Node &node, unsigned int value)
            { return node.value < value; });
        main_chain.insert(lb, Node{tail, static_cast<std::size_t>(-1), false});
    }

    // Extract values
    std::deque<unsigned int> result;
    result.resize(main_chain.size());
    for (std::size_t i = 0; i < main_chain.size(); ++i)
        result[i] = main_chain[i].value;
    return result;
}

// ---------- sortAndPrint ----------

void PmergeMe::sortAndPrint()
{
    // Print "Before:"
    printLine("Before: ", original_.begin(), original_.end());

    // Vector
    std::vector<unsigned int> sortedV;
    const std::chrono::high_resolution_clock::time_point v0 = std::chrono::high_resolution_clock::now();
    sortedV = fordJohnsonVector(vec_);
    const std::chrono::high_resolution_clock::time_point v1 = std::chrono::high_resolution_clock::now();
    timeSortVector_ = std::chrono::duration_cast<std::chrono::microseconds>(v1 - v0);

    // Print "After:" from vector result (conventional)
    printLine("After:  ", sortedV.begin(), sortedV.end());

    // Deque
    std::deque<unsigned int> sortedD;
    const std::chrono::high_resolution_clock::time_point d0 = std::chrono::high_resolution_clock::now();
    sortedD = fordJohnsonDeque(deq_);
    const std::chrono::high_resolution_clock::time_point d1 = std::chrono::high_resolution_clock::now();
    timeSortDeque_ = std::chrono::duration_cast<std::chrono::microseconds>(d1 - d0);

    // Two timing lines (include add + sort)
    const std::chrono::microseconds durVec = timeAddVector_ + timeSortVector_;
    const std::chrono::microseconds durDeq = timeAddDeque_ + timeSortDeque_;

    std::cout << "Time to process a range of " << original_.size()
              << " elements with std::vector : " << durVec.count() << " us" << std::endl;

    std::cout << "Time to process a range of " << original_.size()
              << " elements with std::deque : " << durDeq.count() << " us" << std::endl;
}
