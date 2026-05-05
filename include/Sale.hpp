#ifndef SALE_HPP
#define SALE_HPP

#include "Storage.hpp"
#include "Check.hpp"

class Sale {
private:
    Storage* storage;
    Check currentCheck;
    double cash;
    double income;

public:
    Sale(Storage* st);

    bool sellProduct(unsigned int productId, unsigned int quantity);
    void closeCheck();
    double getCash() const;
    double getIncome() const;
    void setStorage(Storage* st);

    // Методы из UML-диаграммы
    void setCash(double c);
    void Selling();           // будет полноценно реализован
    void ShowIncome();
    void StoreReturner();
};

#endif