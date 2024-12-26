#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

// Base class for all animals. Provides a type and a sound behavior.
class Animal
{
public:
    // Constructors and destructor
    Animal(void);                    // Default constructor
    Animal(Animal const &src);       // Copy constructor
    Animal(std::string const &type); // Constructor with type
    virtual ~Animal(void);           // Virtual destructor for polymorphism

    // Operator overload (Orthodox Canonical Form)
    Animal &operator=(Animal const &src);

    // Getter for the type
    std::string getType(void) const;

    // Virtual function for derived classes to override
    virtual void makeSound(void) const;

protected:
    std::string _type; // Animal type attribute
};

#endif
