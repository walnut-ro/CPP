#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

/**
 * @brief Represents a contact in the phonebook.
 */
class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    /**
     * @brief Constructor
     */
    Contact(void);

    /**
     * @brief Destructor
     */
    ~Contact(void);

    /**
     * @brief Getters
     */
    const std::string getFirstName(void) const;
    const std::string getLastName(void) const;
    const std::string getNickName(void) const;
    const std::string getPhoneNumber(void) const;
    const std::string getDarkestSecret(void) const;

    /**
     * @brief Setters
     */
    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setNickName(const std::string &nickName);
    void setPhoneNumber(const std::string &phoneNumber);
    void setDarkestSecret(const std::string &darkestSecret);

    /**
     * @brief Checks if all fields are populated.
     * @return true if all fields have values, false otherwise.
     */
    bool hasValue(void) const;
};

#endif
