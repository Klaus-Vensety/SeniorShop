#include "Storage.hpp"
#include <iostream>
#include <algorithm>    // для std::find_if

Storage::Storage() {}
Storage::~Storage() {}

bool Storage::addStorageItem(const Product& product) {
    // Проверяем, нет ли уже товара с таким ID
    if (findProduct(product.getID()) != nullptr) {
        std::cout << "Ошибка: товар с ID " << product.getID() << " уже существует!" << std::endl;
        return false;
    }
    products.push_back(product);
    std::cout << "Товар \"" << product.getName() << "\" (ID: " << product.getID() << ") добавлен на склад." << std::endl;
    return true;
}

bool Storage::removeStorageItem(unsigned int id) {
    // Ищем итератор на элемент с нужным ID
    auto it = std::find_if(products.begin(), products.end(),
        [id](const Product& p) { return p.getID() == id; });

    if (it != products.end()) {
        std::cout << "Товар \"" << it->getName() << "\" (ID: " << id << ") удалён со склада." << std::endl;
        products.erase(it);
        return true;
    } else {
        std::cout << "Товар с ID " << id << " не найден." << std::endl;
        return false;
    }
}

Product* Storage::findProduct(unsigned int id) {
    auto it = std::find_if(products.begin(), products.end(),
        [id](const Product& p) { return p.getID() == id; });
    if (it != products.end()) {
        return &(*it);   // возвращаем адрес найденного объекта
    }
    return nullptr;
}

bool Storage::changePrice(unsigned int id, double newPrice) {
    Product* p = findProduct(id);
    if (p) {
        p->setPrice(newPrice);
        std::cout << "Цена товара с ID " << id << " изменена на " << newPrice << std::endl;
        return true;
    }
    std::cout << "Товар с ID " << id << " не найден." << std::endl;
    return false;
}

bool Storage::changeName(unsigned int id, const std::string& newName) {
    Product* p = findProduct(id);
    if (p) {
        p->setName(newName);
        std::cout << "Название товара с ID " << id << " изменено на \"" << newName << "\"" << std::endl;
        return true;
    }
    std::cout << "Товар с ID " << id << " не найден." << std::endl;
    return false;
}

bool Storage::changeCount(unsigned int id, unsigned int newCount) {
    Product* p = findProduct(id);
    if (p) {
        p->setCount(newCount);
        std::cout << "Количество товара с ID " << id << " изменено на " << newCount << std::endl;
        return true;
    }
    std::cout << "Товар с ID " << id << " не найден." << std::endl;
    return false;
}

void Storage::showStorage(int mode) const {
    if (products.empty()) {
        std::cout << "Склад пуст." << std::endl;
        return;
    }
    std::cout << "========== Содержимое склада ==========" << std::endl;
    for (const auto& p : products) {
        p.print();
    }
    std::cout << "=======================================" << std::endl;
}

const std::vector<Product>& Storage::getAll() const {
    return products;
}