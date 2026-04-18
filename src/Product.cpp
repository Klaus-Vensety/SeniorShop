#include "Product.hpp"
#include <iostream>

// Конструктор: инициализация полей с проверкой цены
Product::Product(unsigned int id, const std::string& name, double price, unsigned int count)
    : id(id), name(name), price(price >= 0 ? price : 0.0), count(count) {}

// Реализация геттеров
unsigned int Product::getID() const { return id; }
std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
unsigned int Product::getCount() const { return count; }

// Реализация сеттеров
void Product::setID(unsigned int newID) { id = newID; }
void Product::setName(const std::string& newName) { name = newName; }
void Product::setPrice(double newPrice) {
    if (newPrice >= 0) price = newPrice;
}
void Product::setCount(unsigned int newCount) { count = newCount; }

// Печать товара
void Product::print() const {
    std::cout << "[ID:" << id << "] " << name << " | Цена: " << price << " руб. | В наличии: " << count << " шт." << std::endl;
}