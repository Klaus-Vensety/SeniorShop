#ifndef ADMIN_HPP
#define ADMIN_HPP
#include "User.hpp"
class Admin : public User {
private:
    std::string status;
public:
    Admin(std::string login, std::string password, unsigned int id)
        : User(login, password, "Admin", id), status("Admin") {
    }
    void ShowMenu() override;
    
    
};

#endif
