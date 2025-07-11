#ifndef CPP_STUDY_BUREAUCRAT_HPP
#define CPP_STUDY_BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form; // forward declaration

class Bureaucrat
{

private:
    const std::string name;
    int grade;

public:
    // Canonical form
    Bureaucrat();                                   // default constructor
    Bureaucrat(const std::string &name, int grade); // parameterized constructor
    Bureaucrat(const Bureaucrat &other);            // copy constructor
    Bureaucrat &operator=(const Bureaucrat &other); // copy assignment
    ~Bureaucrat();                                  // destructor

    // Accessors
    std::string getName() const;
    int getGrade() const;

    // Grade modification
    void incrementGrade();
    void decrementGrade();

    void signForm(Form &form);

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
};

// Stream insertion operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif // CPP_STUDY_BUREAUCRAT_HPP
