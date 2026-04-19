#include "Storage.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>

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
    return it != products.end() ? &(*it) : nullptr;
}

bool Storage::updateProduct(unsigned int id, const Product& newData) {
    Product* p = findProduct(id);
    if (p) {
        *p = newData;
        p->setID(id);
        return true;
    }
    return false;
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

std::ostream& operator<<(std::ostream& os, const Storage& storage) {
    for (const auto& p : storage.products)
        os << p << '\n';
    return os;
}