#include <iostream>
#include "Product.hpp"
#include "Storage.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    Storage warehouse;

    // Добавляем товары
    warehouse.addStorageItem(Product(1, "Ноутбук", 55000.0, 5));
    warehouse.addStorageItem(Product(2, "Мышь", 1500.0, 20));
    warehouse.addStorageItem(Product(3, "Клавиатура", 3500.0, 15));

    // Пытаемся добавить дубликат ID
    warehouse.addStorageItem(Product(2, "Мышь беспроводная", 2000.0, 10));

    // Показываем склад
    warehouse.showStorage();

    // Меняем цену
    warehouse.changePrice(1, 52000.0);

    // Удаляем товар
    warehouse.removeStorageItem(3);

    std::cout << "\nПосле изменений:\n";
    warehouse.showStorage();

    return 0;
}