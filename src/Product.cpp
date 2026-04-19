#include "Product.hpp"

Product::Product(unsigned int id, const std::string& name, double price, unsigned int count)
    : id(id), name(name), price(price >= 0 ? price : 0.0), count(count) {}

unsigned int Product::getID() const { return id; }
std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
unsigned int Product::getCount() const { return count; }

void Product::setID(unsigned int newID) { id = newID; }
void Product::setName(const std::string& newName) { name = newName; }
void Product::setPrice(double newPrice) { if (newPrice >= 0) price = newPrice; }
void Product::setCount(unsigned int newCount) { count = newCount; }

// Оператор вывода: формат "id;name;price;count"
std::ostream& operator<<(std::ostream& os, const Product& p) {
    os << p.id << ';' << p.name << ';' << p.price << ';' << p.count;
    return os;
}

// Оператор ввода: читает строку формата "id;name;price;count"
std::istream& operator>>(std::istream& is, Product& p) {
    unsigned int id, count;
    std::string name;
    double price;
    char delim;
    if (is >> id >> delim && delim == ';' &&
        std::getline(is, name, ';') &&
        is >> price >> delim && delim == ';' &&
        is >> count) {
        p.id = id;
        p.name = name;
        p.price = price >= 0 ? price : 0.0;
        p.count = count;
        }
    return is;
}