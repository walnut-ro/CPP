#pragma once

#include <map>
#include <string>
#include <stdexcept>

class BitcoinExchange
{
private:
    std::map<std::string, double> rates_;

public:
    // Canonical + move constructors/assign
    BitcoinExchange() = default;
    ~BitcoinExchange() = default;
    BitcoinExchange(const BitcoinExchange &) = default;
    BitcoinExchange &operator=(const BitcoinExchange &) = default;
    BitcoinExchange(BitcoinExchange &&) = default;
    BitcoinExchange &operator=(BitcoinExchange &&) = default;

    // Loads the CSV database (e.g., "data.csv"), with lines like "YYYY-MM-DD,rate".
    // Throws std::runtime_error on I/O or parse errors.
    void parseFile(const std::string &filepath, char delim = ',');

    // Processes the input file (e.g., "input.txt"), with lines like "YYYY-MM-DD | value".
    // Per-line errors are printed; throws std::runtime_error only on file I/O errors.
    void calcExchangeRate(const std::string &filepath, char delim = '|') const;

    // Returns true if filename ends with the given 'ending' (case-sensitive).
    static bool checkExtension(const std::string &filename, const std::string &ending);

    // Structural + calendar validation for "YYYY-MM-DD".
    static bool checkDate(const std::string &date);

private:
    // Processes a single valid pair (date, value): looks up rate and prints the result.
    void processExchangeRate(const std::string &date, double value) const;

    // Prints: "YYYY-MM-DD => value = value*rate".
    static void formatAndPrintResult(const std::string &date, double value, double resultValue);

    // Finds the rate for an exact date or the closest earlier date.
    // Throws std::out_of_range if no earlier or exact date exists in the DB.
    double rateForDateOrEarlier(const std::string &dateKey) const;

    // ---------- Helpers implemented in .cpp ----------
    // Trims ASCII spaces on both ends (in-place).
    static void trimInPlace(std::string &s);

    // Parses a whole "date | value" line into components; returns false if structurally invalid.
    static bool parseLine(const std::string &line,
                          std::string &outDate,
                          double &outValue,
                          char delim);

    // Parses numeric token to double; returns false if not a number.
    static bool parseValue(const std::string &token, double &out);
};
