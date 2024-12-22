#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
private:
    std::string _name;
    std::string getName(void) const;

public:
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);

    void announce(void);
};

#endif