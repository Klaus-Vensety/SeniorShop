#ifndef CHECK_HPP
#define CHECK_HPP

#include <vector>
#include "Product.hpp"

class Check {
public:
    // Добавляет товар в чек. Если товар с таким ID уже есть, увеличивает количество
    void addItem(const Product& product);

    // Выводит весь чек со строкой итого
    void print() const;

    // Полностью очищает чек для следующей покупки
    void clear();

private:
    std::vector<Product> items; // переименовал для ясности
};

#endif