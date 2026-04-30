#ifndef SALE_HPP
#define SALE_HPP

#include "Storage.hpp"
#include "Check.hpp"

class Sale {
private:
    Storage* storage;      // невладеющий указатель на склад
    Check currentCheck;    // текущий чек
    double cash;           // наличные в кассе
    double income;         // общая выручка

public:
    // Конструктор принимает указатель на склад, обнуляет кассу и доход
    Sale(Storage* st);

    // Продажа товара
    bool sellProduct(unsigned int productId, unsigned int quantity);

    // Закрыть чек (вывести и очистить)
    void closeCheck();

    // Геттеры
    double getCash() const;
    double getIncome() const;

    // Сеттер для смены склада
    void setStorage(Storage* st);
};

#endif