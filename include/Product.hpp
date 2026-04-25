#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <iostream>

class Product {
private:
    unsigned int id;
    std::string name;
    double price;
    unsigned int count;

public:
    // Конструктор по умолчанию
    Product();

    // Конструктор с параметрами
    Product(unsigned int id, const std::string& name, double price, unsigned int count);

    // Геттеры
    unsigned int getID() const;
    std::string getName() const;
    double getPrice() const;
    unsigned int getCount() const;

    // Сеттеры
    void setID(unsigned int newID);
    void setName(const std::string& newName);
    void setPrice(double newPrice);
    void setCount(unsigned int newCount);

    // Операторы для работы с файлами (формат: id;name;price;count)
    friend std::ostream& operator<<(std::ostream& os, const Product& p);
    friend std::istream& operator>>(std::istream& is, Product& p);
};

#endif