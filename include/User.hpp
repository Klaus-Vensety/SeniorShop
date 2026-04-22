#ifndef USER_HPP
#define USER_HPP

#include "include.hpp"

class User {
protected:
    std::string login;
    std::string password;
    std::string status;
    unsigned int id;

public:
    User(std::string login, std::string password, std::string status, unsigned int id);

    virtual void ShowMenu() = 0;
    
    unsigned int getID() const;
    std::string getLogin() const;
    std::string getPassword() const;

    void setLogin(std::string);
    void setPassword(std::string);
    void setId(unsigned int);

    virtual ~User() = default;
};

#endif
