#ifndef CHECK_HPP
#define CHECK_HPP
#include <vector>
#include "Product.hpp"
class Check {
public:
    void CheckPushBack(const Product&);
    void PrintCheck(double);
private:
    std::vector<Product> products;
};
#endif