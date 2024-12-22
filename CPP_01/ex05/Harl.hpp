#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
private:
    // Member functions for each log level
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    // Constructor and public interface
    Harl();
    void complain(std::string level);
};

#endif
