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
    Product(unsigned int id = 0, const std::string& name = "", double price = 0.0, unsigned int count = 0);

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

    // Перегрузка операторов для работы с потоками (файлы/консоль)
    friend std::ostream& operator<<(std::ostream& os, const Product& p);
    friend std::istream& operator>>(std::istream& is, Product& p);
};

#endif // PRODUCT_HPP