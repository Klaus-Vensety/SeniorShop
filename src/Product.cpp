#include "Product.hpp"
#include <iostream>
#include <sstream>

// Старый конструктор (совместимость)
Product::Product(unsigned int id, const std::string& name, double price, unsigned int count)
    : id(id), name(name), brand(""), model(""), storageGB(0),
      price(price >= 0 ? price : 0.0), count(count) {}

// Новый конструктор для телефонов
Product::Product(unsigned int id, const std::string& brand, const std::string& model, int storageGB,
                 double price, unsigned int count)
    : id(id), brand(brand), model(model), storageGB(storageGB),
      price(price >= 0 ? price : 0.0), count(count) {
    updateName();
}

// Вспомогательный метод: собирает полное название
void Product::updateName() {
    std::ostringstream oss;
    oss << brand << " " << model;
    if (storageGB > 0) {
        oss << " " << storageGB << "GB";
    }
    name = oss.str();
}

// Геттеры
unsigned int Product::getID() const { return id; }
std::string Product::getName() const { return name; }
std::string Product::getBrand() const { return brand; }
std::string Product::getModel() const { return model; }
int Product::getStorageGB() const { return storageGB; }
double Product::getPrice() const { return price; }
unsigned int Product::getCount() const { return count; }

// Сеттеры
void Product::setID(unsigned int newID) { id = newID; }
void Product::setName(const std::string& newName) { name = newName; }
void Product::setBrand(const std::string& newBrand) { brand = newBrand; updateName(); }
void Product::setModel(const std::string& newModel) { model = newModel; updateName(); }
void Product::setStorageGB(int gb) { storageGB = gb; updateName(); }
void Product::setPrice(double newPrice) {
    if (newPrice >= 0) price = newPrice;
}
void Product::setCount(unsigned int newCount) { count = newCount; }

// Печать информации о товаре
void Product::print() const {
    std::cout << "[ID:" << id << "] " << name;
    if (storageGB > 0) {
        // уже включено в name, но можно продублировать
    }
    std::cout << " | Цена: " << price << " руб. | В наличии: " << count << " шт." << std::endl;
}