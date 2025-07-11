#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
public:
    // Constructors
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &src);

    // Destructor
    ~ShrubberyCreationForm();

    // Copy assignment
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

    // Accessor
    const std::string &getTarget() const;

    // Required implementation
    void beExecuted() const override;

    // Static grade requirements
    static const int gradeToSign = 145;
    static const int gradeToExecute = 137;

private:
    std::string _target;

    static const std::string _shrubbery;
    static const std::string _shrubberyAlt;
};

#endif // SHRUBBERY_CREATION_FORM_HPP
