#ifndef SUPERADMIN_HPP
#define SUPERADMIN_HPP
#include "User.hpp"
class SuperAdmin : public User {
private:
    std::string status;
public:
    SuperAdmin(std::string login, std::string password, unsigned int id)
        : User(login, password, "SuperAdmin", id), status("SuperAdmin") {
    }
    void SwohSuperAgminMenu() override;


};

#endif
