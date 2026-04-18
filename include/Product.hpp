#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
private:
    unsigned int id;
    std::string name;
    double price;
    unsigned int count;

public:
    // Конструктор с параметрами и значениями по умолчанию
    Product(unsigned int id = 0, const std::string& name = "", double price = 0.0, unsigned int count = 0);

    // Геттеры — только для чтения
    unsigned int getID() const;
    std::string getName() const;
    double getPrice() const;
    unsigned int getCount() const;

    // Сеттеры — для изменения данных
    void setID(unsigned int newID);
    void setName(const std::string& newName);
    void setPrice(double newPrice);      // проверка: цена >= 0
    void setCount(unsigned int newCount);

    // Вывод информации о товаре в консоль
    void print() const;
};

#endif // PRODUCT_HPP