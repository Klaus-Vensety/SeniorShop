#include "Check.hpp"
#include <iostream>
#include <iomanip>

void Check::addItem(const Product& product) {
    for (auto& p : items) {
        if (p.getID() == product.getID()) {
            p.setCount(p.getCount() + product.getCount());
            return;
        }
    }
    items.push_back(product);
}

void Check::print() const {
    double total = 0.0;
    std::cout << "========== ЧЕК ==========\n";

    for (const auto& p : items) {
        std::cout << p.getName();

        // выравнивание имени
        size_t nameLength = p.getName().length();
        size_t totalWidth = 15;
        if (nameLength < totalWidth)
            std::cout << std::string(totalWidth - nameLength, ' ');

        double itemTotal = p.getPrice() * p.getCount();
        std::cout << " " << p.getCount() << " x "
                  << std::fixed << std::setprecision(2) << p.getPrice()
                  << " = " << std::fixed << std::setprecision(2) << itemTotal << "\n";

        total += itemTotal;
    }

    std::cout << "--------------------------\n";
    std::cout << "ИТОГО:                 "
              << std::fixed << std::setprecision(2) << total << "\n";
    std::cout << "==========================\n";
}

void Check::clear() {
    items.clear();
}