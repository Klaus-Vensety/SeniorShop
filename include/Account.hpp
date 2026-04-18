#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <string>
class Account {
public:
    void ChangeUserAccounts();
    void AddNewUser();
    void ShowUsers(int mode = 0);
    void ChangePass();
    bool CheckLogin(const std::string&, const std::string&);
    void DeleteUser();
};
#endif