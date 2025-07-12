#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
public:
    // Constructors
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &src);

    // Destructor
    ~PresidentialPardonForm();

    // Copy assignment
    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

    // Accessor
    const std::string &getTarget() const;

    // Execution logic
    void beExecuted() const override;

    // Grade requirements
    static const int gradeToSign = 25;
    static const int gradeToExecute = 5;

private:
    std::string _target;
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
