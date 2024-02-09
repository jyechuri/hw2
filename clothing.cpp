#include <string>
#include <iostream>
#include <set>
#include <iomanip>

#include "clothing.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string brand, const std::string size)
    : Product(category, name, price, qty),
      brand_(brand),
      size_(size)
{
}

Clothing::~Clothing()
{
}

std::set<std::string> Clothing::keywords() const
{
    std::set<std::string> keys;

    std::set<std::string> set1 = parseStringToWords(name_);
    std::set<std::string> set2 = parseStringToWords(brand_);

    keys = setUnion(set1, set2);

    return keys;
}

std::string Clothing::displayString() const
{
    std::string displayClothing;

    displayClothing = name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";

    return displayClothing;
}

void Clothing::dump(std::ostream &os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << std::endl;
}

/*std::string Clothing::getSize() const
{
    return size_;
}

std::string Clothing::getBrand() const
{
    return brand_;
} */