#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void subjectTest();
void kennelTest(int nbAnimals);
void catCopyTest();

int main(void)
{

    // Subject tests
    subjectTest();

    // Kennel test - Array of Animals
    kennelTest(5);

    // Cat Copy
    catCopyTest();

    std::cout << "\nEnd of tests!" << std::endl;

    return 0;
}

/**
 * @brief Building a Kennel. Instance the class Animal and generate
 * Cats and dogs
 * @param nbAnimals
 */
void kennelTest(int nbAnimals)
{
    std::cout << "\nKennel test! Let's make some animals! (Cats and dogs)" << std::endl;

    Animal *arrAnimals[nbAnimals];

    int nbCats = (nbAnimals / 2);
    int nbDogs = nbAnimals - nbCats;

    std::cout << "We got " << nbAnimals << " Animals in total. " << nbCats << " cats and " << nbDogs << " dogs." << std::endl;

    for (int i = 0; i < nbCats; i++)
    {
        arrAnimals[i] = new Cat();
    }
    for (int i = nbCats; i < nbAnimals; i++)
    {
        arrAnimals[i] = new Dog();
    }

    std::cout << "Cats and dogs out of control!!!" << std::endl;
    for (int i = 0; i < nbAnimals; i++)
    {
        arrAnimals[i]->makeSound();
    }

    std::cout << "Putting the loud animals to rest..." << std::endl;
    for (int i = 0; i < nbAnimals; i++)
    {
        delete arrAnimals[i];
    }
}

/**
 * @brief Identical test from subject
 */
void subjectTest()
{
    std::cout << "\nSubject test!" << std::endl;

    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    delete j;
    delete i;
}

/**
 * @brief Copy test for animals
 */
void catCopyTest()
{
    std::cout << "\nCat Copy test!" << std::endl;

    Cat *catGray = new Cat();

    std::cout << "Cats thinking.... Getting some ideas..." << std::endl;
    catGray->getBrain()->setIdea(0, "Hi Human! You belong to me!");
    catGray->getBrain()->setIdea(1, "Human, what are you doing in my house?!");

    std::cout << "Gray Cat idea (0): \"" << catGray->getBrain()->getIdea(0) << "\"" << std::endl;
    std::cout << "Gray Cat idea (1): \"" << catGray->getBrain()->getIdea(1) << "\"" << std::endl;

    std::cout << "Creating a copy of **Gray Cat**:" << std::endl;

    // Deep Copy
    Cat *catYellow = new Cat(*catGray);

    std::cout << "Yellow/Copy Cat should have the same ideas:" << std::endl;
    std::cout << "Yellow/Copy Cat idea 0: \"" << catYellow->getBrain()->getIdea(0) << "\"" << std::endl;
    std::cout << "Yellow/Copy Cat idea 1: \"" << catYellow->getBrain()->getIdea(1) << "\"" << std::endl;

    std::cout << "Gray Cat Changing and putting new ideas:" << std::endl;
    catGray->getBrain()->setIdea(0, "Here is Gray! Human, where is my toy??");
    catGray->getBrain()->setIdea(1, "Here is Gray! Human, don't bore me...");

    std::cout << "Gray Cat idea (0): \"" << catGray->getBrain()->getIdea(0) << "\"" << std::endl;
    std::cout << "Gray Cat idea (1): \"" << catGray->getBrain()->getIdea(1) << "\"" << std::endl;

    std::cout << "Yellow/Copy Cat should keep the same ideas as before:" << std::endl;
    std::cout << "Yellow/Copy Cat idea 0: \"" << catYellow->getBrain()->getIdea(0) << "\"" << std::endl;
    std::cout << "Yellow/Copy Cat idea 1: \"" << catYellow->getBrain()->getIdea(1) << "\"" << std::endl;

    std::cout << "Free Both cats:" << std::endl;
    delete catGray;
    delete catYellow;
}
