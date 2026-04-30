#include "Sale.hpp"
#include <iostream>

Sale::Sale(Storage* st) : storage(st), cash(0.0), income(0.0) {}

bool Sale::sellProduct(unsigned int productId, unsigned int quantity) {
    // Проверка на нулевое количество
    if (quantity == 0) return false;

    // Проверка наличия склада
    if (!storage) return false;

    // Ищем товар
    Product* p = storage->findProduct(productId);
    if (!p) return false;                         // товар не найден
    if (p->getCount() < quantity) return false;   // недостаточно на складе

    // Уменьшаем количество на складе
    p->setCount(p->getCount() - quantity);

    // Создаём временный объект с количеством = quantity для чека
    Product soldItem = *p;          // копируем id, name, price
    soldItem.setCount(quantity);    // но количество как в продаже

    // Добавляем в чек
    currentCheck.addItem(soldItem);

    // Увеличиваем кассу и доход
    double cost = soldItem.getPrice() * quantity;
    cash += cost;
    income += cost;

    return true;
}

void Sale::closeCheck() {
    currentCheck.print();   // печатаем чек
    currentCheck.clear();   // очищаем для следующей покупки
}

double Sale::getCash() const { return cash; }
double Sale::getIncome() const { return income; }

void Sale::setStorage(Storage* st) { storage = st; }