#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Default Constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", ShrubberyCreationForm::gradeToSign, ShrubberyCreationForm::gradeToExecute),
      _target("Unknown")
{
    std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

/**
 * @brief Copy constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

/**
 * @brief Target constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation Form", ShrubberyCreationForm::gradeToSign, ShrubberyCreationForm::gradeToExecute),
      _target(target.empty() ? "Unknown" : target)
{
    std::cout << "ShrubberyCreationForm target constructor called." << std::endl;
}

/**
 * @brief Destructor
 */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

/**
 * @brief Assignment operator
 */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    std::cout << "ShrubberyCreationForm copy assignment operator called." << std::endl;
    if (this != &src)
        this->_target = src._target;
    return *this;
}

/**
 * @brief Accessor - get target
 */
const std::string &ShrubberyCreationForm::getTarget() const
{
    return _target;
}

/**
 * @brief beExecuted — called by AForm::execute()
 * Creates <target>_shrubbery file with tree ASCII art
 */
void ShrubberyCreationForm::beExecuted() const
{
    std::ofstream ofs(_target + "_shrubbery", std::ofstream::out | std::ofstream::app);

    if (!ofs)
    {
        std::cerr << "Failed to open file: " << _target + "_shrubbery" << std::endl;
        return;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const std::string &art = (std::rand() % 2) ? ShrubberyCreationForm::_shrubbery : ShrubberyCreationForm::_shrubberyAlt;

    ofs << art;
    std::cout << "Shrubbery planted in file: " << _target + "_shrubbery" << std::endl;
    ofs.close();
}

/**
 * @brief Static ASCII trees
 */
const std::string ShrubberyCreationForm::_shrubbery =
    R"(

         /\
        /**\
       /****\   /\
      /      \ /**\
     /  /\    /    \
    /__/__\__/______\
       ||     ||
       ||     ||
       ||     ||

)";

const std::string ShrubberyCreationForm::_shrubberyAlt =
    R"(

        &&& &&  & &&
     && &\/&\|& ()|/ @, &&
     &\/(/&/&||/& /_/)_&/_&
  &() &\/&|()|/&\/ '%" & ()
 &_\_&&_\ |& |&&/&__%_/_& &&
&&   && & &| &| /& & % ()& /&&
 ()&_---()&\&\|&&-&&--%---()~
     &&     \|||
             |||
             |||
             |||
       , -=-~  .-^- _
)";
