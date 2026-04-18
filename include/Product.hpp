#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
private:
    unsigned int id;
    std::string name;          // автоматически формируется из brand + model
    std::string brand;
    std::string model;
    int storageGB;             // объём памяти в ГБ (0, если не указан)
    double price;
    unsigned int count;

public:
    // ----- Конструкторы -----
    // Старый конструктор (для обратной совместимости)
    Product(unsigned int id = 0, const std::string& name = "", double price = 0.0, unsigned int count = 0);

    // Новый конструктор для телефонов
    Product(unsigned int id, const std::string& brand, const std::string& model, int storageGB,
            double price, unsigned int count);

    // ----- Геттеры -----
    unsigned int getID() const;
    std::string getName() const;       // возвращает brand + model + storage
    std::string getBrand() const;
    std::string getModel() const;
    int getStorageGB() const;
    double getPrice() const;
    unsigned int getCount() const;

    // ----- Сеттеры -----
    void setID(unsigned int newID);
    void setName(const std::string& newName);   // для совместимости
    void setBrand(const std::string& newBrand);
    void setModel(const std::string& newModel);
    void setStorageGB(int gb);
    void setPrice(double newPrice);
    void setCount(unsigned int newCount);

    // ----- Вывод -----
    void print() const;

private:
    void updateName();   // обновляет поле name при изменении brand/model/storage
};

#endif // PRODUCT_HPP