#ifndef USER_HPP
#define USER_HPP
#include <string>
class User {
public:
    virtual ~User() = default;
    virtual void showMenu() = 0;
};
#endif