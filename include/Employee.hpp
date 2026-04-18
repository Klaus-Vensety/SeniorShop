#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include "User.hpp"
class Employee : public User {
public:
    void showMenu() override;
};
#endif