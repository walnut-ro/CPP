#ifndef CPP_STUDY_FORM_HPP
#define CPP_STUDY_FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Form
{

private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

    Form(); // Default constructor is private to prevent instantiation without parameters

public:
    // Canonical Form
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &copy);
    Form &operator=(const Form &copy);
    ~Form();

    // Getters
    std::string getName() const;
    bool getSignatureStatus() const;
    int getGradeSign() const;
    int getGradeExecute() const;

    // Signing
    void beSigned(const Bureaucrat &bureaucrat);

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
};

// Operator <<
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif // CPP_STUDY_FORM_HPP
