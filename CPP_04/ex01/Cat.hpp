#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
    Cat(void);           // Default constructor
    Cat(Cat const &src); // Copy constructor
    ~Cat(void);          // Destructor

    Cat &operator=(Cat const &src); // Copy assignment operator

    void makeSound(void) const; // Override makeSound

    // Getter for the Brain object
    Brain *getBrain(void) const;

private:
    Brain *_brain; // Pointer to Cat's Brain
};

#endif
