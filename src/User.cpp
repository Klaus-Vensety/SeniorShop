#include "User.hpp"

User::User(std::string login, std::string password, std::string status, unsigned int id)
    : login(login), password(password), status(status), id(id) {
}

unsigned int User::getID() const
{
    return id;
}

std::string User::getLogin() const
{
    return login;
}

std::string User::getPassword() const
{
    return password;
}
