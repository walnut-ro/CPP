#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

// Derived class implementing specific behavior for a Dog
class Dog : public Animal
{
public:
    // Constructors and destructor
    Dog(void);           // Default constructor
    Dog(Dog const &src); // Copy constructor
    ~Dog(void);          // Destructor

    // Operator overload (Orthodox Canonical Form)
    Dog &operator=(Dog const &src);

    // Overrides the base class's makeSound to provide a dog-specific sound
    void makeSound(void) const;
};

#endif
