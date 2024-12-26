#ifndef W_ANIMAL_H
#define W_ANIMAL_H

#include <string>

// Base class for demonstrating non-polymorphic behavior
class WrongAnimal
{
public:
    // Constructors and destructor
    WrongAnimal(void);                    // Default constructor
    WrongAnimal(WrongAnimal const &src);  // Copy constructor
    WrongAnimal(std::string const &type); // Constructor with type
    virtual ~WrongAnimal(void);           // Destructor

    // Operator overload (Orthodox Canonical Form)
    WrongAnimal &operator=(WrongAnimal const &src);

    // Getter for the type
    std::string getType(void) const;

    // Non-virtual function to demonstrate the absence of polymorphism
    void makeSound(void) const;

protected:
    std::string _type; // Animal type attribute
};

#endif
