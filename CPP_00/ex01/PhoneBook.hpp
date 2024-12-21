#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
private:
    int _index;
    Contact _contactList[8];

    void indexHandler(void);
    void displayAllContact(void) const;
    void displaySingleContact(std::string input) const;
    void truncate(std::string str) const;

    bool validInput(const std::string &input, const std::string &allowedChar, size_t minLength) const;
    bool isValidField(const std::string &input, bool justNumber) const;
    bool isValidIndexDetail(const std::string &input) const;

    void handleInput(const std::string &prompt, void (Contact::*setter)(const std::string &), bool justNumber);
    void handleDetailContact(void);

public:
    PhoneBook(void);
    ~PhoneBook(void);

    void addContact(void);
    void searchContact(void);
};

#endif
