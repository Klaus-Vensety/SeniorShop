#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <vector>
#include <string>
#include "Product.hpp"

class Storage {
private:
    std::vector<Product> products;

public:
    Storage() = default;
    ~Storage() = default;

    bool addProduct(const Product& product);
    bool removeProduct(unsigned int id);
    Product* findProduct(unsigned int id);
    bool updateProduct(unsigned int id, const Product& newData);
    const std::vector<Product>& getAll() const;

    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);

    friend std::ostream& operator<<(std::ostream& os, const Storage& storage);
};

#endif // STORAGE_HPP