#ifndef CPP_STUDY_AFORM_HPP
#define CPP_STUDY_AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{

private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    // Canonical form
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &copy);
    AForm &operator=(const AForm &copy);
    virtual ~AForm();

    // Accessors
    std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Core logic
    void beSigned(const Bureaucrat &bureaucrat);
    void execute(const Bureaucrat &executor) const;

    // Abstract method — must be implemented in child
    virtual void beExecuted() const = 0;

    // Exceptions
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const noexcept override;
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const noexcept override;
    };

    class AlreadySignedException : public std::exception
    {
    public:
        const char *what() const noexcept override;
    };

    class NotSignedException : public std::exception
    {
    public:
        const char *what() const noexcept override;
    };
};

// Output stream overload
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif // CPP_STUDY_AFORM_HPP
