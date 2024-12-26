#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void BaseClass();
void dogByDerivedDogClass();
void dogByBaseClass();
void catByDerivedCatClass();
void catByBaseClass();
void subjectTest();
void wrongTest();
void wrongSubjectTest();

int main(void)
{
    // // Base class test
    // BaseClass();

    // // Dog tests
    // dogByDerivedDogClass();
    // dogByBaseClass();

    // // Cat tests
    // catByDerivedCatClass();
    // catByBaseClass();

    // // Wrong Test
    // wrongTest();

    // // Wrong Subject
    // wrongSubjectTest();

    // Subject tests
    subjectTest();

    return (0);
}

/**
 * @brief Tests with base class
 *
 */
void BaseClass()
{
    std::cout << "Animal - Base class tests" << std::endl;
    Animal *animal = new Animal();
    std::cout << "Animal type: " << animal->getType() << std::endl;
    animal->makeSound();
    delete animal;
    std::cout << std::endl;
}

/**
 * @brief Dog instantiate class, but by Dog class /Derived class
 *
 */
void dogByDerivedDogClass()
{
    std::cout << "Dog by derived Dog class" << std::endl;
    Dog *dog = new Dog();
    std::cout << "Dog type: " << dog->getType() << std::endl;
    dog->makeSound();
    delete dog;
    std::cout << std::endl;
}

/**
 * @brief Dog instantiate class,but by base class
 */
void dogByBaseClass()
{
    std::cout << "Dog by Animal base class" << std::endl;
    Animal *dog = new Dog();
    std::cout << "Animal type: " << dog->getType() << std::endl;
    dog->makeSound();
    delete dog;
    std::cout << std::endl;
}

/**
 * @brief Cat instantiate class, but by Cat class /Derived class
 *
 */
void catByDerivedCatClass()
{
    std::cout << "Cat by derived Cat class" << std::endl;
    Cat *cat = new Cat();
    std::cout << "Cat type: " << cat->getType() << std::endl;
    cat->makeSound();
    delete cat;
    std::cout << std::endl;
}

/**
 * @brief Cat instantiate class,but by base class
 */
void catByBaseClass()
{
    std::cout << "Cat by Animal base class" << std::endl;
    Animal *cat = new Cat();
    std::cout << "Animal type: " << cat->getType() << std::endl;
    cat->makeSound();
    delete cat;
    std::cout << std::endl;
}

/**
 * @brief Identical test from subject
 */
void subjectTest()
{
    std::cout << "Subject test!" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete j;
    delete i;
    delete meta;
    std::cout << std::endl;
}

/**
 * @brief Test from subject - Wrong call
 */
void wrongSubjectTest()
{
    std::cout << "[Wrong] Subject test!" << std::endl;
    const WrongAnimal *meta = new WrongAnimal();
    const Animal *j = new Dog();
    const WrongAnimal *i = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete j;
    delete i;
    delete meta;
    std::cout << std::endl;
}

void wrongTest()
{
    {
        std::cout << "Wrong Animal" << std::endl;
        const WrongAnimal *animal = new WrongAnimal();
        std::cout << "WrongAnimal type: " << animal->getType() << std::endl;
        animal->makeSound();
        delete animal;
        std::cout << std::endl;
    }
    {
        std::cout << "Wrong Cat By Wrong Cat Class" << std::endl;
        const WrongCat *cat = new WrongCat();
        std::cout << "WrongCat type: " << cat->getType() << std::endl;
        cat->makeSound();
        delete cat;
        std::cout << std::endl;
    }
    {
        std::cout << "WrongCat By WrongAnimal Class" << std::endl;
        const WrongAnimal *cat = new WrongCat();
        std::cout << "WrongAnimal type: " << cat->getType() << std::endl;
        cat->makeSound();
        delete cat;
        std::cout << std::endl;
    }
}
