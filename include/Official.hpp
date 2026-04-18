#ifndef OFFICIAL_HPP
#define OFFICIAL_HPP
#include "Account.hpp"
#include "Storage.hpp"
#include "Sale.hpp"
class Official {
public:
    void Logout();
    Account& getAccount();
    Storage& getStore();
    Sale& getSale();
private:
    Account account;
    Storage storage;
    Sale sale;
};
#endif