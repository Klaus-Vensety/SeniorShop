#ifndef SHOP_HPP
#define SHOP_HPP
#include <vector>
class User;
class Shop {
public:
    void Start();
    bool Login();
    void CompletionUsersVector();
private:
    std::vector<User*> users;
};
#endif