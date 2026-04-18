#ifndef ADMIN_HPP
#define ADMIN_HPP
#include "User.hpp"
class Admin : public User {
public:
    void showMenu() override;
};
#endif