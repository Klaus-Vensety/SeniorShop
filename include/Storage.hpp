#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <vector>
#include <string>
#include "Product.hpp"

class Storage {
private:
    std::vector<Product> products;

public:
    Storage();

    // ---------- Основные методы ----------
    bool addProduct(const Product& product);
    bool removeProduct(unsigned int id);
    Product* findProduct(unsigned int id);
    const std::vector<Product>& getAll() const;
    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);

    // ---------- Методы, совместимые с main.cpp ----------
    void addStorageItem(const Product& p);      // обёртка над addProduct
    bool removeStorageItem(unsigned int id);    // обёртка над removeProduct
    void showStorage() const;                   // вывод склада
    void changePrice(unsigned int id, double newPrice); // обёртка над setPrice

    // ---------- Методы из UML-диаграммы ----------
    void CreateStore();
    void CreateNewStorage();
    void ShowStore(int mode = 0);
    void AddStoreItem(const Product& p);
    void RemoveStoreItem(unsigned int id);
    void ChangePrice(unsigned int id, double newPrice);
    void ChangeName(unsigned int id, const std::string& newName);
    void CheckStorage();
    void AddNewItem();
    void DeleteItem(unsigned int id);
};

#endif