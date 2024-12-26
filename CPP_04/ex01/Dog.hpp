#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog(void);           // Default constructor
    Dog(Dog const &src); // Copy constructor
    ~Dog(void);          // Destructor

    Dog &operator=(Dog const &src); // Copy assignment operator

    void makeSound(void) const; // Override makeSound

private:
    Brain *_brain; // Pointer to Dog's Brain
};

#endif
