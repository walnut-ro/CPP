#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
public:
    // Constructors
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &src);

    // Destructor
    ~RobotomyRequestForm();

    // Copy assignment
    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

    // Accessor
    const std::string &getTarget() const;

    // Execution logic (override required method)
    void beExecuted() const override;

    // Grade requirements
    static const int gradeToSign = 72;
    static const int gradeToExecute = 45;

private:
    std::string _target;
};

#endif // ROBOTOMY_REQUEST_FORM_HPP
