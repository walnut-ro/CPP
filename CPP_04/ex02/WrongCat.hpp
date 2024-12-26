#ifndef W_CAT_H
#define W_CAT_H

#include "WrongAnimal.hpp"

// Derived class demonstrating non-polymorphic behavior from WrongAnimal
class WrongCat : public WrongAnimal
{
public:
    // Constructors and destructor
    WrongCat(void);                // Default constructor
    WrongCat(WrongCat const &src); // Copy constructor
    ~WrongCat(void);               // Destructor

    // Operator overload (Orthodox Canonical Form)
    WrongCat &operator=(WrongCat const &src);

    // Overrides makeSound, but no polymorphism will occur due to non-virtual base class
    void makeSound(void) const;
};

#endif
