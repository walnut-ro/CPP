#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

// Derived class implementing specific behavior for a Cat
class Cat : public Animal
{
public:
    // Constructors and destructor
    Cat(void);           // Default constructor
    Cat(Cat const &src); // Copy constructor
    ~Cat(void);          // Destructor

    // Operator overload (Orthodox Canonical Form)
    Cat &operator=(Cat const &src);

    // Overrides the base class's makeSound to provide a cat-specific sound
    void makeSound(void) const;
};

#endif
