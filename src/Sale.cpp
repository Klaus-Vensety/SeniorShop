#include "Sale.hpp"
#include <iostream>
#include <limits>

Sale::Sale(Storage* st) : storage(st), cash(0.0), income(0.0) {}

bool Sale::sellProduct(unsigned int productId, unsigned int quantity) {
    if (quantity == 0) return false;
    if (!storage) return false;

    Product* p = storage->findProduct(productId);
    if (!p || p->getCount() < quantity) return false;

    p->setCount(p->getCount() - quantity);
    Product soldItem = *p;
    soldItem.setCount(quantity);
    currentCheck.addItem(soldItem);

    double cost = soldItem.getPrice() * quantity;
    cash += cost;
    income += cost;
    return true;
}

void Sale::closeCheck() {
    currentCheck.print();
    currentCheck.clear();
}

double Sale::getCash() const { return cash; }
double Sale::getIncome() const { return income; }
void Sale::setStorage(Storage* st) { storage = st; }

// ---------- Реализация методов из диаграммы ----------
void Sale::setCash(double c) {
    cash = c;
}

void Sale::Selling() {
    if (!storage) {
        std::cout << "Ошибка: склад не задан!" << std::endl;
        return;
    }

    std::cout << "===== Режим продажи =====" << std::endl;
    std::cout << "Вводите ID товара и количество (0 для завершения)" << std::endl;

    while (true) {
        unsigned int id, qty;
        std::cout << "ID товара: ";
        std::cin >> id;
        if (id == 0) break;

        std::cout << "Количество: ";
        std::cin >> qty;

        if (!std::cin) {
            std::cout << "Неверный ввод, попробуйте снова." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (sellProduct(id, qty)) {
            std::cout << "Продажа выполнена." << std::endl;
        } else {
            std::cout << "Ошибка: товар не найден или недостаточно на складе." << std::endl;
        }
    }

    std::cout << "Завершение продажи. Итоговый чек:" << std::endl;
    closeCheck();
}

void Sale::ShowIncome() {
    std::cout << "Общий доход: " << income << std::endl;
}

void Sale::StoreReturner() {
    // Заглушка для возврата товара
}