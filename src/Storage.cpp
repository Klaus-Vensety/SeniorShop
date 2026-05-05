#include "Storage.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>

Storage::Storage() {}

// ---------- Основные методы ----------
bool Storage::addProduct(const Product& product) {
    if (findProduct(product.getID()) != nullptr) return false;
    products.push_back(product);
    return true;
}

bool Storage::removeProduct(unsigned int id) {
    auto it = std::find_if(products.begin(), products.end(),
        [id](const Product& p) { return p.getID() == id; });
    if (it != products.end()) {
        products.erase(it);
        return true;
    }
    return false;
}

Product* Storage::findProduct(unsigned int id) {
    auto it = std::find_if(products.begin(), products.end(),
        [id](const Product& p) { return p.getID() == id; });
    return (it != products.end()) ? &(*it) : nullptr;
}

const std::vector<Product>& Storage::getAll() const {
    return products;
}

bool Storage::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return false;
    for (const auto& p : products)
        out << p << '\n';
    return true;
}

bool Storage::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return false;
    products.clear();
    Product p;
    while (in >> p)
        products.push_back(p);
    return true;
}

// ---------- Методы для main.cpp ----------
void Storage::addStorageItem(const Product& p) {
    addProduct(p);
}

bool Storage::removeStorageItem(unsigned int id) {
    return removeProduct(id);
}

void Storage::showStorage() const {
    if (products.empty()) {
        std::cout << "Склад пуст" << std::endl;
        return;
    }
    for (const auto& p : products) {
        std::cout << p << std::endl; // operator<< выводит id;name;price;count
    }
}

void Storage::changePrice(unsigned int id, double newPrice) {
    Product* p = findProduct(id);
    if (p) p->setPrice(newPrice);
}

// ---------- Методы из UML-диаграммы ----------
void Storage::CreateStore() {
    // Заглушка
}
void Storage::CreateNewStorage() {
    products.clear();
}
void Storage::ShowStore(int mode) {
    showStorage();
}
void Storage::AddStoreItem(const Product& p) {
    addProduct(p);
}
void Storage::RemoveStoreItem(unsigned int id) {
    removeProduct(id);
}
void Storage::ChangePrice(unsigned int id, double newPrice) {
    changePrice(id, newPrice);
}
void Storage::ChangeName(unsigned int id, const std::string& newName) {
    Product* p = findProduct(id);
    if (p) p->setName(newName);
}
void Storage::CheckStorage() { /* заглушка */ }
void Storage::AddNewItem()   { /* заглушка */ }
void Storage::DeleteItem(unsigned int id) {
    removeProduct(id);
}