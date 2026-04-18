#include "Official.hpp"
void Official::Logout() {}
Account& Official::getAccount() { return account; }
Storage& Official::getStore() { return storage; }
Sale& Official::getSale() { return sale; }