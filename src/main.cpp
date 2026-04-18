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

    std::cout << "===== Магазин телефонов =====" << std::endl;

    Storage warehouse;

    // Добавляем телефоны через новый конструктор
    warehouse.addStorageItem(Product(1, "Apple", "iPhone 15 Pro", 256, 129990.0, 5));
    warehouse.addStorageItem(Product(2, "Samsung", "Galaxy S25", 512, 89990.0, 10));
    warehouse.addStorageItem(Product(3, "Xiaomi", "14 Ultra", 512, 69990.0, 15));
    warehouse.addStorageItem(Product(4, "Google", "Pixel 9 Pro", 128, 79990.0, 8));

    // Пытаемся добавить дубликат ID
    warehouse.addStorageItem(Product(2, "Samsung", "Galaxy S25+", 256, 99990.0, 5));

    // Показываем склад
    warehouse.showStorage();

    // Меняем цену
    warehouse.changePrice(1, 127990.0);

    // Удаляем товар
    warehouse.removeStorageItem(3);

    std::cout << "\nПосле изменений:\n";
    warehouse.showStorage();

    return 0;
}