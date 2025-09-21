#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <limits>

// Convert double to string and trim trailing zeros and the trailing dot.
// replaces the old toTrimmedString
// --- replace your current toTrimmedString with this one ---
#include <cmath>
#include <sstream>
#include <iomanip>

// Round to 6 decimal places in integer space, then trim trailing zeros.
static std::string toTrimmedString(double v)
{
    const long double p = 1000000.0L; // 1e6
    long double x = static_cast<long double>(v);
    x = std::llround(x * p) / p; // integer rounding to 6 dp

    std::ostringstream oss;
    oss.setf(std::ios::fixed);
    oss << std::setprecision(6) << static_cast<double>(x);

    std::string s = oss.str();
    if (s.find('.') != std::string::npos)
    {
        while (!s.empty() && s.back() == '0')
            s.pop_back();
        if (!s.empty() && s.back() == '.')
            s.pop_back();
    }
    return s;
}

// Parse numeric token fully (no trailing junk). Returns false if invalid/NaN/inf.
static bool parseValueStrict(const std::string &token, double &out)
{
    if (token.empty())
        return false;
    char *endp = NULL;
    out = std::strtod(token.c_str(), &endp);
    if (endp == token.c_str() || *endp != '\0')
        return false;
    if (!std::isfinite(out))
        return false;
    return true;
}

// --------------------- BitcoinExchange: utilities ---------------------

bool BitcoinExchange::checkExtension(const std::string &filename, const std::string &ending)
{
    std::string::size_type dot = filename.rfind('.');
    if (dot == std::string::npos || dot + 1 >= filename.size())
        return false;
    return filename.substr(dot + 1) == ending;
}

bool BitcoinExchange::checkDate(const std::string &date)
{
    // Structural check: "YYYY-MM-DD" (length 10, digits in positions, hyphens at 4 and 7)
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (std::size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    // Parse numbers
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1)
        return false;

    // Days per month with leap-year handling
    static const int mdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dim = mdays[month - 1];
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && leap)
        dim = 29;

    return day <= dim;
}

// Trim ASCII whitespace in-place (member function version to match the header).
void BitcoinExchange::trimInPlace(std::string &s)
{
    const char *ws = " \t\r\n\f\v";
    std::string::size_type b = s.find_first_not_of(ws);
    if (b == std::string::npos)
    {
        s.clear();
        return;
    }
    std::string::size_type e = s.find_last_not_of(ws);
    s.erase(e + 1);
    s.erase(0, b);
}

// --------------------- database (CSV) ---------------------

void BitcoinExchange::parseFile(const std::string &filepath, char delim)
{
    std::ifstream in(filepath.c_str());
    if (!in)
    {
        // Database file is part of the project; throwing here is reasonable.
        throw std::runtime_error("Error: could not open database file.");
    }
    if (!checkExtension(filepath, "csv") || delim != ',')
    {
        throw std::invalid_argument("Invalid file extension or delimiter");
    }

    std::string line;
    bool first = true;
    while (std::getline(in, line))
    {
        if (line.empty())
            continue;

        // Skip header if present (first non-empty line equals one of known headers)
        if (first)
        {
            std::string tmp = line;
            trimInPlace(tmp);
            if (tmp == "date,exchange_rate" || tmp == "date,rate" || tmp == "date")
            {
                first = false;
                continue;
            }
            first = false;
        }

        std::stringstream ss(line);
        std::string date, rateStr;
        if (!std::getline(ss, date, ','))
            continue;
        if (!std::getline(ss, rateStr))
            continue;

        trimInPlace(date);
        trimInPlace(rateStr);

        if (!checkDate(date))
            continue;

        double r = 0.0;
        if (!parseValueStrict(rateStr, r))
            continue;

        // Assign the rate (do NOT sum, do NOT round).
        rates_[date] = r;
    }
}

// --------------------- core processing ---------------------

void BitcoinExchange::calcExchangeRate(const std::string &filepath, char delim) const
{
    std::ifstream in(filepath.c_str());
    if (!in)
    {
        // Exact message required by the subject for the input file.
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    if (delim != '|')
    {
        // Treat wrong delimiter as bad input for the whole file path (not strictly specified).
        std::cerr << "Error: bad input => " << filepath << std::endl;
        return;
    }

    std::string line;
    bool first = true;

    while (std::getline(in, line))
    {
        std::string original = line; // keep exact line for error echo
        trimInPlace(line);
        if (line.empty())
            continue;

        // Optional header "date | value" (exact spelling)
        if (first)
        {
            first = false;
            if (line == "date | value")
                continue;
            // otherwise fall through as a data line
        }

        // Split by '|'
        std::string::size_type bar = line.find('|');
        if (bar == std::string::npos)
        {
            std::cerr << "Error: bad input => " << original << std::endl;
            continue;
        }

        std::string date = line.substr(0, bar);
        std::string valueToken = line.substr(bar + 1);
        trimInPlace(date);
        trimInPlace(valueToken);

        if (!checkDate(date))
        {
            std::cerr << "Error: bad input => " << original << std::endl;
            continue;
        }

        double value = 0.0;
        if (!parseValueStrict(valueToken, value))
        {
            std::cerr << "Error: bad input => " << original << std::endl;
            continue;
        }
        if (value < 0.0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000.0)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // Find the rate (exact date or closest earlier) and print result.
        try
        {
            double r = rateForDateOrEarlier(date);
            const double res = r * value;
            // Print in the exact required format.
            formatAndPrintResult(date, value, res);
        }
        catch (const std::out_of_range &)
        {
            // No earlier or equal date exists in the DB for this input line.
            std::cerr << "Error: bad input => " << original << std::endl;
        }
    }
}

double BitcoinExchange::rateForDateOrEarlier(const std::string &dateKey) const
{
    if (rates_.empty())
    {
        throw std::out_of_range("empty database");
    }

    std::map<std::string, double>::const_iterator it = rates_.lower_bound(dateKey);

    if (it == rates_.end())
    {
        // All keys are less than dateKey -> take the last (closest earlier)
        --it;
        return it->second;
    }

    if (it->first == dateKey)
    {
        // Exact match
        return it->second;
    }

    // lower_bound points to the first element >= dateKey; if it's greater, step back
    if (it == rates_.begin())
    {
        // There is no earlier date
        throw std::out_of_range("no earlier date");
    }
    --it;
    return it->second;
}

// --------------------- output ---------------------

void BitcoinExchange::processExchangeRate(const std::string &date, double value) const
{
    // Not used in this implementation path; kept for API compatibility if needed.
    try
    {
        double r = rateForDateOrEarlier(date);
        const double res = r * value;
        formatAndPrintResult(date, value, res);
    }
    catch (const std::out_of_range &)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
    }
}

void BitcoinExchange::formatAndPrintResult(const std::string &date,
                                           double value,
                                           double resultValue)
{
    std::cout << date
              << " => "
              << toTrimmedString(value)
              << " = "
              << toTrimmedString(resultValue)
              << std::endl;
}
