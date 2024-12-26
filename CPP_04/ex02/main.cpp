#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    Animal *AnimalArray[2];

    AnimalArray[0] = new Dog();
    AnimalArray[1] = new Cat();

    std::cout << "\nTEST!" << std::endl;
    Cat cat;
    cat.getBrain().setIdea(0, "I LOVE TUNA");
    Cat copyCat(cat);
    copyCat.getBrain().setIdea(0, "I LOVE SARDINS");
    Cat assignCat = cat;
    assignCat.getBrain().setIdea(0, "I HATE FISH");
    std::cout << "Cat 1: " << cat.getBrain().getIdea(0) << std::endl;
    std::cout << "Cat 2: " << copyCat.getBrain().getIdea(0) << std::endl;
    std::cout << "Cat 3: " << assignCat.getBrain().getIdea(0) << std::endl;
    std::cout << std::endl;

    AnimalArray[0]->makeSound();
    AnimalArray[1]->makeSound();
    std::cout << std::endl;

    delete AnimalArray[0];
    delete AnimalArray[1];

    return (0);
}