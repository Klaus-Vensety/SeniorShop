#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <vector>
#include <string>
#include "Product.hpp"

class Storage {
private:
    std::vector<Product> products;   // Динамический массив товаров

public:
    Storage();                        // Конструктор
    ~Storage();                       // Деструктор

    // Добавление товара. Возвращает false, если товар с таким ID уже есть
    bool addStorageItem(const Product& product);

    // Удаление товара по ID. Возвращает true при успехе
    bool removeStorageItem(unsigned int id);

    // Поиск товара по ID. Возвращает указатель на товар или nullptr
    Product* findProduct(unsigned int id);

    // Изменение цены товара по ID
    bool changePrice(unsigned int id, double newPrice);

    // Изменение названия товара по ID
    bool changeName(unsigned int id, const std::string& newName);

    // Изменение количества товара по ID
    bool changeCount(unsigned int id, unsigned int newCount);

    // Вывод всех товаров на экран. mode зарезервирован для будущего использования
    void showStorage(int mode = 0) const;

    // Получить константную ссылку на вектор (для безопасного доступа извне)
    const std::vector<Product>& getAll() const;
};

#endif // STORAGE_HPP