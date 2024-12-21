#include <iostream>
#include "PhoneBook.hpp"

#define CMD_ADD "1"
#define CMD_SEARCH "2"
#define CMD_EXIT "3"

void showMenu(bool firstTime)
{
    std::cout << "\nPhoneBook Menu:\n";
    if (firstTime)
    {
        std::cout << "Welcome to your PhoneBook!\n";
    }
    std::cout << "1. ADD Contact\n";
    std::cout << "2. SEARCH Contacts\n";
    std::cout << "3. EXIT\n";
}

int main(void)
{
    PhoneBook pBook;
    bool firstTime = true;

    std::string value;
    while (true)
    {
        showMenu(firstTime);
        firstTime = false;
        std::cout << "> ";
        std::getline(std::cin, value);

        if (value == CMD_ADD || value == "ADD")
        {
            pBook.addContact();
        }
        else if (value == CMD_SEARCH || value == "SEARCH")
        {
            pBook.searchContact();
        }
        else if (value == CMD_EXIT || value == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}
