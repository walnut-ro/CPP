#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _index(-1) {}

PhoneBook::~PhoneBook(void)
{
    // Nothing to clean up since there's no dynamic allocation.
}

void PhoneBook::addContact(void)
{
    indexHandler();
    handleInput("First Name: ", &Contact::setFirstName, false);
    handleInput("Last Name: ", &Contact::setLastName, false);
    handleInput("Nick Name: ", &Contact::setNickName, false);
    handleInput("Phone Number: ", &Contact::setPhoneNumber, true);
    handleInput("Darkest Secret: ", &Contact::setDarkestSecret, false);
}

void PhoneBook::searchContact(void)
{
    if (_index == -1)
    {
        std::cout << "PhoneBook is empty.\n";
        return;
    }
    displayAllContact();
    handleDetailContact();
}

void PhoneBook::displayAllContact(void) const
{
    std::cout << "     Index|First Name| Last Name|  Nickname\n";
    for (int i = 0; i < 8; i++)
    {
        if (!_contactList[i].hasValue())
        {
            break;
        }
        std::cout << std::setw(10) << i << "|";
        truncate(_contactList[i].getFirstName());
        truncate(_contactList[i].getLastName());
        truncate(_contactList[i].getNickName());
        std::cout << "\n";
    }
}

void PhoneBook::displaySingleContact(std::string input) const
{
    if (input.length() == 1 && std::isdigit(input[0]))
    {
        int index = input[0] - '0';
        std::cout << "First Name: " << _contactList[index].getFirstName() << "\n";
        std::cout << " Last Name: " << _contactList[index].getLastName() << "\n";
        std::cout << "  Nickname: " << _contactList[index].getNickName() << "\n";
        std::cout << "Phone Number: " << _contactList[index].getPhoneNumber() << "\n";
        std::cout << "Darkest Secret: " << _contactList[index].getDarkestSecret() << "\n";
    }
    else
    {
        std::cout << "Invalid index.\n";
    }
}

void PhoneBook::handleDetailContact(void)
{
    std::string input;
    std::cout << "Index: ";
    std::getline(std::cin, input);
    if (!isValidIndexDetail(input))
    {
        handleDetailContact();
    }
    else
    {
        displaySingleContact(input);
    }
}

bool PhoneBook::isValidIndexDetail(const std::string &input) const
{
    if (input.length() != 1 || !std::isdigit(input[0]))
    {
        std::cout << "Invalid input.\n";
        return false;
    }
    int index = input[0] - '0';
    if (index < 0 || index >= 8 || !_contactList[index].hasValue())
    {
        std::cout << "Invalid index.\n";
        return false;
    }
    return true;
}

void PhoneBook::handleInput(const std::string &prompt, void (Contact::*setter)(const std::string &), bool justNumber)
{
    std::string input;

    while (true)
    { // Loop until valid input is provided
        std::cout << prompt;
        std::getline(std::cin, input);

        if (isValidField(input, justNumber))
        {                                          // Validate input
            (_contactList[_index].*setter)(input); // Set the value if valid
            break;                                 // Exit loop on valid input
        }
        else
        {
            std::cout << "Invalid input. Please try again.\n";
        }
    }
}

bool PhoneBook::isValidField(const std::string &input, bool justNumber) const
{
    return validInput(input, justNumber ? "0123456789" : "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ", 1);
}

bool PhoneBook::validInput(const std::string &input, const std::string &allowedChars, size_t minLength) const
{
    if (input.length() < minLength)
    {
        std::cout << "Invalid input.\n";
        return false;
    }
    for (size_t i = 0; i < input.length(); i++)
    {
        if (allowedChars.find(input[i]) == std::string::npos)
        {
            std::cout << "Invalid input.\n";
            return false;
        }
    }
    return true;
}

void PhoneBook::truncate(std::string str) const
{
    if (str.length() > 10)
    {
        str.resize(9);
        str += ".";
    }
    std::cout << std::setw(10) << str << "|";
}

void PhoneBook::indexHandler(void)
{
    _index = (_index + 1) % 8;
}
