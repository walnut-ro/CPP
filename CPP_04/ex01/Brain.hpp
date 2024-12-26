#ifndef BRAIN_H
#define BRAIN_H

#include <string>

#define BRAIN_SIZE 100

class Brain
{
public:
    // Constructors and destructor
    Brain(void);             // Default constructor
    Brain(Brain const &src); // Copy constructor
    ~Brain(void);            // Destructor

    // Copy assignment operator
    Brain &operator=(Brain const &src);

    // Accessors for ideas
    std::string getIdea(int index) const;             // Get an idea by index
    void setIdea(int index, std::string const &idea); // Set an idea by index

private:
    std::string _ideas[BRAIN_SIZE]; // Array to store ideas
};

#endif
