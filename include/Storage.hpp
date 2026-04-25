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

    // Добавить товар (false, если ID уже существует)
    bool addProduct(const Product& product);

    // Удалить товар по ID (true, если удалён)
    bool removeProduct(unsigned int id);

    // Найти товар по ID (nullptr, если не найден)
    Product* findProduct(unsigned int id);

    // Получить все товары (только для чтения)
    const std::vector<Product>& getAll() const;

    // Сохранить склад в файл (перезаписывает файл)
    bool saveToFile(const std::string& filename) const;

    // Загрузить склад из файла (заменяет текущие данные)
    bool loadFromFile(const std::string& filename);
};

#endif