#ifndef SUPERADMIN_HPP
#define SUPERADMIN_HPP
#include "User.hpp"
class SuperAdmin : public User {
public:
    void showMenu() override;
};
#endif